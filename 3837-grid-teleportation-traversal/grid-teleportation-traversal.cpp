class Solution {
public:
    int minMoves(vector<string>& mat) {
        int n=mat.size(); int m=mat[0].size();
        if(mat[0][0]=='#') return -1;
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,0,0});
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='#') dist[i][j]=-1;
            }
        }
        dist[0][0]=0;
        set<char> st;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!pq.empty()){
            auto [d,r,c]=pq.top(); pq.pop();
            
            if(r==n-1 && c==m-1) return dist[r][c];

            if(mat[r][c]>='A' && mat[r][c]<='Z' && st.find(mat[r][c])==st.end()){
                st.insert(mat[r][c]);

                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(mat[i][j]==mat[r][c] && (r!=i || c!=j)){
                            if(d<dist[i][j]){
                                pq.push({d,i,j});
                                dist[i][j]=d;
                            }
                        }
                    }
                }
            }
            for(int i=0;i<4;i++){
                int nr=r+dx[i],nc=c+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]!='#'){
                    if(dist[nr][nc]>1+d){
                        dist[nr][nc]=1+d;
                        pq.push({dist[nr][nc],nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};