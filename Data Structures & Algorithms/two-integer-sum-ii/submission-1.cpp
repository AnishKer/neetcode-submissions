class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0 , right = nums.size()-1;
        while(left<right){
            if(nums[left]+nums[right] > target){
                right--;
                continue;
            }
            else if(nums[left]+nums[right] < target){
                left++;
                continue;
            }
            else{
                return {left+1,right+1};
            }
        }
        return {-1,-1};
    }
};
