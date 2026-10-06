class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        vector<vector<bool>> vis (n, vector<bool> (m , false));
        queue<pair<int,int>> q;

        for(int i=0 ; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        int row[] = {1,-1,0,0};
        int col[] = {0,0,1,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            // vis[r][c] = true;
            q.pop();

            for(int i =0 ;i<4;i++){
                int newr = r + row[i];
                int newc = c + col[i];
                if(newr>=0 && newc>=0 && newr<n && newc<m && grid[newr][newc] == INT_MAX){
                    grid[newr][newc] = grid[r][c] + 1;
                    q.push({newr,newc});
                }
            }
        }
        
    }
};
