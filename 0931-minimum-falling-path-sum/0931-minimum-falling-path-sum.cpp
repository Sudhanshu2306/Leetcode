typedef long long ll;
#include<bits/stdc++.h>
class Solution {
public:
    
    ll solve(int i,int j, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        // base case
        int m=matrix[0].size();
        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[0][j];

        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i-1,j,matrix,dp)+matrix[i][j];
        int ld=solve(i-1,j-1,matrix,dp)+matrix[i][j];
        int rd=solve(i-1,j+1,matrix,dp)+matrix[i][j];

        return dp[i][j]=min({up,ld,rd});

    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MAX;
        
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // for(int i=0;i<m;i++){
        //     ans=min((ll)ans,solve(n-1,i,matrix,dp));
        // }
        // return int(ans);
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // base case
        
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                ll up=dp[i-1][j]+matrix[i][j];
                ll right=1e9; ll left=1e9;
                if(j>0) left=dp[i-1][j-1] +matrix[i][j];
                // else left= INT_MAX;
                if(j+1<m) right=dp[i-1][j+1] +matrix[i][j];
                // else right = INT_MAX;
                dp[i][j] = min({up,left,right});
            }
        }
        
        for(int i=0;i<m;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;  
    }
};
        
        
        
     