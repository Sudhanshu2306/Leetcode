class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> d(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        d[0][0]=0;
        pq.push({0,{0,0}});

        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            int dist=x.first;
            int row=x.second.first;
            int col=x.second.second;
            
            if(row==n-1 && col==m-1) return dist;
            for(int i=0;i<4;i++){
                int nr=row+dx[i];
                int nc=col+dy[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int nd=max(dist, abs(heights[row][col]-heights[nr][nc]));
                    if(nd<d[nr][nc]){
                        d[nr][nc]=nd;
                        pq.push({nd,{nr,nc}});
                    }
                }
            }
        }
        return -1;

    }
};