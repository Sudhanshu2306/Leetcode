class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        int n=grid.size();
        if(i==n-1) return dp[i][j]=grid[i][j];

        if(dp[i][j]!=-1007) return dp[i][j];
        
        int x=INT_MAX;
        for(int k=0;k<n;k++){
            if(k!=j){
                x=min(grid[i][j]+f(i+1,k,grid,dp),x);
            }
        }
        return dp[i][j]=x;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(n,-1007));

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,f(0,i,grid,dp));
        }
        return ans;
    }
};