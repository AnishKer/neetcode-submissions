class Solution {
public:
    int maxArea(vector<int>& nums) {
        int left = 0 , right = nums.size()-1;
        int area = 0;
        while(left<right){
            if(nums[left]<nums[right]){
                area = max(area , (right-left)*min(nums[left],nums[right]));
                left++;
            }else{
                area = max(area , (right-left)*min(nums[left],nums[right]));
                right--;
            }
        }
        return area;
    }
};
