class Solution {
    void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<int>> &vis){
        vis[i][j]=1;
        
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        int n=mat.size();
        int m=mat[0].size();
        
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && mat[nr][nc]=='O'){
                dfs(nr,nc,mat,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // vector<vector<char>> ans=mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && mat[i][j]=='O' && vis[i][j]==0){
                    dfs(i,j,mat,vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O') mat[i][j]='X';
            }
        }
    }
};