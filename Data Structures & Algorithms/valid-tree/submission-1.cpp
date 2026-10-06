class Solution {
public:
    bool dfs(int u , int par ,vector<bool>& vis , vector<int> adj[]){
        vis[u]=true;
        for(auto v : adj[u]){
            if(!vis[v]){
                if(dfs(v,u,vis,adj)) return true;
            }else if(v!=par){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis (n,false);
        if(!vis[0]){
            if(dfs(0,-1,vis,adj)) return false;
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
