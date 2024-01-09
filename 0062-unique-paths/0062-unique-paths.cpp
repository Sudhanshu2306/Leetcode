class Solution {
public:
    int solve(int i,int j, vector<vector<int>> &dp){
        // top-down approach + memoisation
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i-1,j,dp);
        int left=solve(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<long long>> dp(m,vector<long long>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[0][0]=1;
                else{
                    long long up=0,left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};