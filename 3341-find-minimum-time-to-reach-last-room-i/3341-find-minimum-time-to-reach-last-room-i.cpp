
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9+100));

        int dx[]={0,-1,0,1};
        int dy[]={1,0,-1,0};

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        dist[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [time,r,c]=pq.top(); pq.pop();
            if(r==n-1 && c==m-1) return time;

            for(int k=0;k<4;k++){
                int nr=r+dx[k],nc=c+dy[k];
                if(nr<n && nr>=0 && nc<m && nc>=0){
                    int nt=max(time,a[nr][nc])+1;
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