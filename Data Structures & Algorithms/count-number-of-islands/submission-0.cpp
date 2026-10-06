class Solution {
public:
    void helper(int i , int j , vector<vector<bool>> &vis , vector<vector<char>> &grid , int n , int m){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j] == '0') return;
        vis[i][j] = true;

        helper(i-1,j,vis,grid,n,m);
        helper(i+1,j,vis,grid,n,m);
        helper(i,j-1,vis,grid,n,m);
        helper(i,j+1,vis,grid,n,m);
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size() , vector<bool> (grid[0].size(),false)) ;
        int count =0;
        for(int i = 0 ;i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    helper(i,j,vis,grid,grid.size(),grid[0].size());
                    count ++;
                }
            }
        }
        return count;
    }
};
