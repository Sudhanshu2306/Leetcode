class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,0));
        priority_queue<tuple<int,int,int>> pq;
        pq.push({health-grid[0][0],0,0});

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(!pq.empty()){
            auto [h,i,j]=pq.top(); pq.pop();
            if(i==n-1 && j==m-1) return health>=1;

            for(int k=0;k<4;k++){
                int ni=i+dx[k], nj=j+dy[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m && dist[ni][nj]<h-grid[ni][nj]){
                    dist[ni][nj]=h-grid[ni][nj];
                    pq.push({dist[ni][nj],ni,nj});
                }
            }
        }
        return false;
    }
};