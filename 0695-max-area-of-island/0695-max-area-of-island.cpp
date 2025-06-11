class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j){
        vis[i][j]=1;
        int area=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && !vis[ni][nj] && grid[ni][nj]==1){
                area+=dfs(grid,vis,ni,nj);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int area=dfs(grid,vis,i,j);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};