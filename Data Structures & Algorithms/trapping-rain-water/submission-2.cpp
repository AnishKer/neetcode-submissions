class Solution {
public:
    int trap(vector<int>& nums) {
        int left = 0 , right = nums.size()-1;
        int leftmax = nums[left] , rightmax = nums[right];

        int sum =0;

        while(left <= right){
            leftmax = max(leftmax , nums[left]);
            rightmax = max(rightmax , nums[right]);

            if(leftmax < rightmax){
                sum += leftmax-nums[left];
                left++;
            }else{
                sum += rightmax-nums[right];
                right--;
            }

        }
        return sum;
    }
};
