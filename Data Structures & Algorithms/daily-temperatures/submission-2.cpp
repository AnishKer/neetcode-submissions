class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans (temp.size(),0);
        stack<pair<int,int>> stack;

        for(int i = 0 ; i < temp.size() ; i++){
            while(stack.size()>0 && temp[i]>stack.top().first){
                
                ans[stack.top().second] = i - stack.top().second;
                stack.pop();
            }
            stack.push({temp[i],i});
        }
        return ans;
    }
};
