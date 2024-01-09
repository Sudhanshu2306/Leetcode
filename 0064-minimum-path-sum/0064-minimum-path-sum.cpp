typedef long long ll;

class Solution {
public:
    ll solve(int i,int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        
        if(dp[i][j]!=-1) return dp[i][j];
        ll up=grid[i][j]+solve(i-1,j,grid,dp);
        ll left=grid[i][j]+solve(i,j-1,grid,dp);
        
        return dp[i][j]=min(up,left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dp(m,-1);
        // return solve(n-1,m-1,grid,dp);
        dp[0]=grid[0][0];
        for(int i=0;i<n;i++){
            vector<int> temp(m);
            for(int j=0;j<m;j++){
                if(i==0 && j==0) temp[j]=grid[i][j];
                else{
                    int up=0,left=0;
                    if(i>0) up=dp[j]+grid[i][j];
                    else up=INT_MAX;
                    if(j>0) left=temp[j-1]+grid[i][j];
                    else left=INT_MAX;
                    temp[j]=min(up,left);
                }
            }
            dp=temp;
        }
        return dp[m-1];
    }
};