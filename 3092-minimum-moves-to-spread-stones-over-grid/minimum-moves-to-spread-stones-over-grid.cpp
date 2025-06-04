class Solution {
public:
    int f(vector<vector<int>> &a){
        int ans=1e5;
        bool flag=true;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a[i][j]==0){
                    flag=false;
                    for(int x=0;x<3;x++){
                        for(int y=0;y<3;y++){
                            if(a[x][y]>1){
                                a[x][y]--; a[i][j]=1; 
                                ans=min(ans,abs(x-i)+abs(y-j)+f(a));
                                a[i][j]=0; a[x][y]++;
                            }
                        }
                    }
                }
            }
        }
        return flag?0:ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        return f(grid);
    }
};