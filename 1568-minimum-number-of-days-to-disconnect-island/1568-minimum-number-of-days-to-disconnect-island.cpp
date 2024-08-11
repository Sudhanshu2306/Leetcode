class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;

        for(int i=0;i<4;i++){
            int nr=r+dx[i]; int nc=c+dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                dfs(nr,nc,grid,vis);
            }
        }
    }

    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && v[i][j]==0){
                    c++;
                    dfs(i,j,grid,v);
                }
            }
        }
        if(c>1 || c==0) return 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vector<vector<int>> vis(n,vector<int>(m,0));
                    grid[i][j]=0;
                    // function
                    int count=0;
                    for(int k=0;k<n;k++){
                        for(int l=0;l<m;l++){
                            if(grid[k][l]==1 && vis[k][l]==0){
                                count++;
                                dfs(k,l,grid,vis);
                            } 
                        }
                    }
                    if(count>1 || count==0) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};