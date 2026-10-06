class Solution {
public:
    int dfs(int i , int j, vector<vector<bool>>& vis, vector<vector<int>>& grid, int n ,int m){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]==0){
            return 0;
        }

        vis[i][j] = true;
        int ans = 1;
        ans += dfs(i+1,j,vis,grid,n,m);   
        ans += dfs(i,j+1,vis,grid,n,m);   
        ans += dfs(i-1,j,vis,grid,n,m);   
        ans += dfs(i,j-1,vis,grid,n,m);
        return ans;   
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis (n , vector<bool>(m , false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    ans = max(ans,dfs(i,j,vis,grid,n,m));
                }
            }
        }
        return ans;
    }
};
