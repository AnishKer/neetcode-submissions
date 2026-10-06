class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(string x : strs){
            s += x + "~";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string str;
        for(char ch : s){
            if(ch!='~'){
                str.push_back(ch);
            }else{
                ans.push_back(str);
                str = "";
            }
        }
        return ans;
    }
};
