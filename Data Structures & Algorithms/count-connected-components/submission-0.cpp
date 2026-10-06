class Solution {
public:
    void dfs(int u , vector<bool>& vis, vector<int> adj[]){
        
        vis[u]=true;
        for(auto v : adj[u]){
            if(!vis[v]){
                dfs(v,vis,adj);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};
