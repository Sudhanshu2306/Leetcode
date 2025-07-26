class Solution {
public:
    vector<int> dx={0,1,0,-1};
    vector<int> dy={1,0,-1,0};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return 0;

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front(); q.pop();
            int d=dist[r][c];

            for(int k=0;k<4;k++){
                int nr=r+dx[k], nc=c+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc]>d+1){
                    dist[nr][nc]=d+1;
                    q.push({nr,nc});
                }
            }
        }

        priority_queue<tuple<int,int,int>> pq;
        pq.push({dist[0][0],0,0});
        vector<vector<int>> vis(n,vector<int>(n,0));
        while(!pq.empty()){
            auto [d,r,c]=pq.top(); pq.pop();

            if(r==n-1 && c==n-1) return d;
            vis[r][c]=1;
            for(int k=0;k<4;k++){
                int nr=r+dx[k], nc=c+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0){
                    int x=min(d,dist[nr][nc]);
                    pq.push({x,nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        return -1;
    }
};