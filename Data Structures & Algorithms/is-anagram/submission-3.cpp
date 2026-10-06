class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> store_s (26,0);
        vector<int> store_t (26,0);

        for(int i =0 ; i<s.size() ; i++){
            store_s[s[i] - 'a']++;
        }
        for(int i = 0 ; i<t.size() ; i++){
            store_t[t[i] - 'a']++;

        }


        return store_s==store_t ? true :false;
    }
};
