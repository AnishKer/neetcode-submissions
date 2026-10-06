class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        set <char> allchar;
        for(auto ch : words){
            for(auto c : ch){
                allchar.insert(c);
                }       
            }
        unordered_map<char,string> adj;
        unordered_map<char,int> freq;

        for(auto ch : allchar){
            freq[ch]=0;
        }

        int n = words.size();
        for(int i=0;i<n-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(),s2.size());
            bool found = false;
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]].push_back(s2[j]);
                    freq[s2[j]]++;
                    found = true;
                    break;
                }
            }
            if(!found && s1.size()>s2.size()){
                return "";
            } 
        }

        queue<char> q;
        for(auto ch:allchar){
            if(freq[ch] == 0){
                q.push(ch);
            }
        }
        string ans="";
        while(!q.empty()){
            char node = q.front();
            q.pop();
            ans += node;
            for(auto ch:adj[node]){
                freq[ch]--;
                if(freq[ch]==0){
                    q.push(ch);
                }
            }
        }
        if(ans.size() != allchar.size()) return "";
        return ans;
    }
};
