class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> s;
        vector<int> ans (temp.size() , 0);

        for(int i = 0 ; i < temp.size() ; i++){
            int t = temp[i];

            while(s.size()>0 && t>s.top().first){
                pair <int,int> p = s.top();
                s.pop();
                ans[p.second] = i - p.second;
            }

            s.push({t,i});
        }
        return ans;
    }
};
