class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> arr1 (26,0);

        for(char ch : s1){
            arr1[ch - 'a']++;
        }

        for(int i = 0 ; i < s2.length()-s1.length()+1 ; i++){
            vector<int> arr2 (26,0);
            for(int j = i ; j<i+s1.length()  ; j++){
                arr2[s2[j] - 'a']++;
            }

            if(arr1 == arr2) return true;
        }
        return false;
    }
};
