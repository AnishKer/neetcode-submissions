class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& vel) {
        vector<pair<int,int>> pair;
        for(int i = 0 ;i < pos.size() ; i++){
            pair.push_back({pos[i],vel[i]});
        }
        sort(pair.rbegin(),pair.rend());
        vector<double> ans;
        for(auto x : pair){
            ans.push_back((double)(tar-x.first)/x.second);
            if(ans.size() >=2 && ans.back()<=ans[ans.size()-2]){
                ans.pop_back();
            }
        }
        return ans.size();
    }
};
