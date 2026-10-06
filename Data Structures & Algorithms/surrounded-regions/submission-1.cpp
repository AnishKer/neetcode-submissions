class Solution {
public:
    void dfs(int u,int v , vector<vector<bool>>& vis, vector<vector<char>>& board,int n,int m){
        if(u<0 || v<0 || u>=n || v>=m || vis[u][v] || board[u][v]=='X'){
            return;
        }

        vis[u][v] = true;
        dfs(u+1,v,vis,board,n,m);
        dfs(u,v+1,vis,board,n,m);
        dfs(u-1,v,vis,board,n,m);
        dfs(u,v-1,vis,board,n,m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size() ,m =board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0 ;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,n,m);
            }
            if(!vis[i][m-1] && board[i][m-1] =='O'){
                dfs(i,m-1,vis,board,n,m);
            }
        }
        for(int i = 0 ;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,vis,board,n,m);
            }
            if(!vis[n-1][i] && board[n-1][i] =='O'){
                dfs(n-1,i,vis,board,n,m);
            }
        }

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    vis[i][j]=true;
                    board[i][j]='X';
                }
            }
        }

    }
};
