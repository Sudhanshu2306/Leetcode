class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        pair<int,int> src={0,0};
        pair<int,int> dest={n-1,n-1};
        if(grid[0][0]==0 && n==1) return 1;

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        q.push({1,{0,0}});
        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,-1,-1,-1,0,1,1,1};

        while(!q.empty()){
            int wt=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && wt+1<dist[nr][nc]){
                    dist[nr][nc]=1+wt;
                    q.push({wt+1,{nr,nc}});
                }
            }
        }
        if(dist[n-1][n-1]!=INT_MAX) return dist[n-1][n-1];
        return -1;
    }
};