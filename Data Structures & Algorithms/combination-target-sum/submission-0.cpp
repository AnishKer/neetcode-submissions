class Solution {
public:

    void helper(vector<int>& nums , vector<vector<int>>& ans , vector<int>& sub , int target , int i){
        if(target == 0){
            ans.push_back(sub);
            return;
        }

        if(target <0 || i>=nums.size()) return;

        sub.push_back(nums[i]);
        helper(nums,ans,sub,target-nums[i],i);
        sub.pop_back();
        helper(nums,ans,sub,target,i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> sub;

        helper(nums, ans , sub , target , 0);
        return ans;
    }
};
