class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            int weight=x.first; int i=x.second.first; int j=x.second.second;
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                int w=0;
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    if(grid[ni][nj]==1) w=1;
                
                    if(weight+w<dist[ni][nj]){
                        dist[ni][nj]=weight+w;
                        pq.push({weight+w,{ni,nj}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};