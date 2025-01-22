class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    vector<vector<int>> highestPeak(vector<vector<int>>& a) {
        int n=a.size(); int m=a[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]=a[i][j]==1?0:-1;
                if(a[i][j]==0) q.push({i,j});
            } 
        }
        int level=1;
        while(!q.empty()){
            int x=q.size();
            for(int i=0;i<x;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int nr=r+dx[k], nc=c+dy[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && a[nr][nc]==-1){
                        a[nr][nc]=level;
                        q.push({nr,nc});
                    }
                }
            }
            level++;
        }
        return a;
    }
};