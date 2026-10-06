class Solution {
public:

    void helper(vector<int>& nums , vector<vector<int>>& ans , vector<int>& sub , int i){
        if(i>=nums.size()){
            ans.push_back(sub);
            return ;
        }

        sub.push_back(nums[i]);
        helper(nums, ans , sub , i+1);
        sub.pop_back();
        helper(nums, ans , sub , i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;

        helper(nums , ans, sub ,0);
        return ans;
    }
};
