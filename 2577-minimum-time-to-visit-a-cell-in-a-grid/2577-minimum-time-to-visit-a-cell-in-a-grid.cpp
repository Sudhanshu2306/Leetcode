class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();

        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        vector<int> dx={0,1,0,-1};
        vector<int> dy={1,0,-1,0};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {time,i,j}
        pq.push({grid[0][0],0,0});
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            int t=x[0]; int i=x[1]; int j=x[2];
            vis[i][j]=1;
            if(i==n-1 && j==m-1) return t;
            for(int k=0;k<4;k++){
                int ni=i+dx[k]; int nj=j+dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==0){
                    int diff=grid[ni][nj]-t;
                    if(diff%2==0) pq.push({max(t+1,grid[ni][nj]+1),ni,nj});
                    else pq.push({max(t+1,grid[ni][nj]),ni,nj});
                }
            }
        }
        return -1; // hypothetical, we will always reach the end
    }
};