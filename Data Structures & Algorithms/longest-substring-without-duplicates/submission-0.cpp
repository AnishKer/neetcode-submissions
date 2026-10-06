class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int ans =0 ;
        unordered_set<char> set;
        for(int i = 0 ; i<s.size() ; i++){
            while(set.find(s[i]) != set.end()){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[i]);
            ans = max(ans , i - left +1);
        }
        return ans;
    }
};
