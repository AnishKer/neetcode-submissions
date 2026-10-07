class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    longestConsecutive(nums) {
        if(nums.length === 0) return 0
        let set = new Set(nums)
        let ans = 0;

        for(const num of nums){
            if(!set.has(num-1)){
                let curr = num
                let count = 1

                while(set.has(curr+1)){
                    count++
                    curr++
                }
                ans = Math.max(count,ans)
            }
        }
        return ans;
    }
}
