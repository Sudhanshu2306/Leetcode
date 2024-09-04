class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& obstacles) {
        int n=c.size();
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int x=0,y=0;
        int dir=0;
        set<vector<int>> st(obstacles.begin(),obstacles.end());
        int maxi=0;
        for(int i=0;i<n;i++){
            if(c[i]==-1) dir=(dir+1)%4;
            else if(c[i]==-2) dir=(dir+3)%4;
            else{
                for(int j=0;j<c[i];j++){
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];
                    if(st.find({nx,ny})!=st.end()) break;
                    x=nx; y=ny;
                    maxi=max(maxi,x*x+y*y);
                }
            }
        }
        return maxi;
    }
};