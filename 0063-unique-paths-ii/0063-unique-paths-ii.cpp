class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<long long> dp(n,-1);
        dp[0]=1;
        for(int i=0;i<m;i++){
            vector<long long> temp(n,0);
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) temp[j]=0;
                else if(i==0 && j==0) temp[0]=1;
                else{
                    long long up=0,left=0;
                    if(i>0) up=dp[j];
                    if(j>0) left=temp[j-1];
                    temp[j]=up+left;
                }
            }
            dp=temp;
        }
        return dp[n-1];
        

    }
};