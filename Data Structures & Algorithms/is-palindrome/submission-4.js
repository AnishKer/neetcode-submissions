class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isPalindrome(s) {
        let left = 0 
        let right = s.length-1

        while(left<right){
            while( left<right && !((s[left].toLowerCase()>='a' && s[left].toLowerCase()<='z') || (s[left]>='0' && s[left]<='9'))){
                left++
            }
            while( left<right && !((s[right].toLowerCase()>='a' && s[right].toLowerCase()<='z') || (s[right]>='0' && s[right]<='9'))){
                right--
            }
        if(s[left].toLowerCase() !== s[right].toLowerCase()) return false
        left++
        right--
        }
        return true

    }
}
