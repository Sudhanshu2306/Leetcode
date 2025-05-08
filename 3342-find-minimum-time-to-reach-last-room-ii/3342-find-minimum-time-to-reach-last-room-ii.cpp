class Solution {
public:
    int minTimeToReach(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;

        dist[0][0]=0; pq.push({0,0,0});
        int dx[]={0,-1,0,1};
        int dy[]={1,0,-1,0};
        while(!pq.empty()){
            auto [t,r,c]=pq.top(); pq.pop();
            if(r==n-1 && c==m-1) return t;

            for(int k=0;k<4;k++){
                int nc=c+dy[k],nr=r+dx[k];
                if(nc>=0 && nc<m && nr>=0 && nr<n){
                    int nt=max(t,a[nr][nc])+((nr+nc)%2==1?1:2);
                    if(nt<dist[nr][nc]){
                        dist[nr][nc]=nt;
                        pq.push({nt,nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};