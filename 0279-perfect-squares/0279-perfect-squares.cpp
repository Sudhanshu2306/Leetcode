class Solution {
public:

    int f(int target,vector<int> &dp){
        if(target==0) return 0;
        if(dp[target]!=INT_MAX) return dp[target];
        int picks=INT_MAX;
        for(int i=1;i*i<=target;i++){
            int x=i*i;
            picks=min(picks,1+f(target-x,dp));
        }
        return dp[target]= picks;
    }

    int tabulation(int n){
        vector<long long> dp(n+1,INT_MAX);
        // base case
        dp[0]=0;
        for(int tar=1;tar<=n;tar++){
            long long picks=INT_MAX;
            for(int j=1;j*j<=tar;j++){
                int x=j*j;
                picks=min(picks,1+dp[tar-x]);
            }
            dp[tar]=picks;
        }
        return dp[n];
    }

    // dp is 1d, 1 for remaining sum
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        // return f(n,dp);
        return tabulation(n);
    }
};