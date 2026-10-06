class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    void helper(vector<int>& nums , vector<int>& sub , int target , int i){
        if(target == 0){
            if(s.find(sub) == s.end()){
            s.insert(sub);
            ans.push_back(sub);
            return ;
            }
        }

        if(target<0 || i>=nums.size()){
            return ;
        }

        sub.push_back(nums[i]);
        helper(nums,sub,target-nums[i],i+1);
        sub.pop_back();
        helper(nums,sub,target,i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub;
        sort(candidates.begin(),candidates.end());
        helper(candidates , sub , target, 0);

        return ans;
    }
};
