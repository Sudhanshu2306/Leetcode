typedef tuple<int,int,int> tp;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        priority_queue<tp,vector<tp>,greater<tp>> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));
        // {cost,x,y}
        pq.push({0,0,0});

        while(!pq.empty()){
            auto z=pq.top(); pq.pop();
            int cost=get<0>(z), x=get<1>(z), y=get<2>(z);
            // if(vis[x][y]==1) continue;
            vis[x][y]=1;

            if(x==n-1 && y==m-1) return cost;
            for(int i=0;i<4;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0){
                    if(i==grid[x][y]-1) pq.push({cost,nx,ny});
                    else pq.push({cost+1,nx,ny});
                }
            }
        }
        return -1;
    }
};