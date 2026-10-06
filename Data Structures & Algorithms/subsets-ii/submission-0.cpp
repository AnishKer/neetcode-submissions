class Solution {
public:

    vector<vector<int>> ans;
    void helper(vector<int>& nums , vector<int>& sub ,int i){
        if(i == nums.size()) {
            ans.push_back(sub);
            return ;
        }

        sub.push_back(nums[i]);
        helper(nums,sub,i+1);
        sub.pop_back();

        int idx = i+1;
        while(idx<nums.size() && nums[idx-1] == nums[idx]){
            idx++;
        }

        helper(nums,sub,idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        sort(nums.begin(),nums.end());
        helper(nums,sub,0);
        return ans;
    }
};
