class Solution {
public:
    
    int solve(int i,int j, vector<vector<int>> &triangle,vector<vector<int>> &dp){
        if(i==triangle.size()-1)
            return triangle[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int down=solve(i+1,j,triangle,dp)+triangle[i][j];
        int diagonal=solve(i+1,j+1,triangle,dp)+triangle[i][j];
        
        return dp[i][j] = min(down,diagonal);
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        // return solve(0,0,triangle,dp);
        
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                
                int down=dp[i+1][j]+triangle[i][j];
                int diagonal=dp[i+1][j+1]+triangle[i][j];
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};