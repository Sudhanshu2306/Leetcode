class Solution {
public:

    int f(int target,vector<int> &dp){
        // base case
        if(target==0) return 0;

        if(dp[target]!=1e9) return dp[target];
        int ans=INT_MAX;
        for(int i=1;i*i<=target;i++){
            int sq=i*i;
            ans=min(ans,1+f(target-sq,dp));
        }
        return dp[target]=ans;
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
        vector<int> dp(n+1,1e9);
        return f(n,dp);
        // return tabulation(n);
    }
};