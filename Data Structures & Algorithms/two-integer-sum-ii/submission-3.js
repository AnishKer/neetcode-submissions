class Solution {
    /**
     * @param {number[]} numbers
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, tar) {
        const map = new Map()
        for(let i =0;i<nums.length;i++){
            const toFind = tar-nums[i]
            if(map.has(toFind)){
                return [map.get(toFind)+1,i+1]
            }
            map.set(nums[i],i)
        }
        return []
    }
}
