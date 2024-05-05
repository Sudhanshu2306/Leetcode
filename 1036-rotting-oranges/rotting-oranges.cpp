class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        int res=0;
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 || grid[i][j]==2) count++;
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            res=max(t,res);
            
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=1;
                }
            }
        }
        int count2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]) count2++;
            }
        }
        if(count==count2) return res;
        else return -1;
    }
};