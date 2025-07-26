class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        bool flag=false;
        int ans=1e9;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0){
                    flag=true;
                    for(int k=0;k<3;k++){
                        for(int l=0;l<3;l++){
                            if(grid[k][l]>1){
                                grid[k][l]--; grid[i][j]++;
                                ans=min(ans,abs(i-k)+abs(l-j)+minimumMoves(grid));
                                grid[k][l]++; grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        return flag?ans:0;
    }
};