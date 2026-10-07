class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    productExceptSelf(nums) {
        let res = new Array(nums.length).fill(1)
        let prefix = 1
        for(let i=0;i<nums.length;i++){
            res[i]*= prefix
            //1,2,4,6
            prefix*=nums[i]
            //1,1,2,8
        }
        let suffix = 1
        for(let i = nums.length-1 ;i>=0 ;i--){
            res[i]*= suffix
            suffix*=nums[i]
        }
        return res
    }
}
