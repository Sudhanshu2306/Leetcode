class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0) return false;

        int total=n*n-1;
        int count=1;
        int x=0, y=0;
        int dx[]={-2,-2,-1,-1,1,1,2,2};
        int dy[]={-1,1,2,-2,2,-2,1,-1};
        while(count<=total){
            bool flag=false;
            for(int i=0;i<8;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    if(grid[nx][ny]==count){
                        count++; x=nx, y=ny;
                        flag=true;
                        break;
                    }
                }
            }
            if(!flag) return false;
        }
        return true;
    }
};