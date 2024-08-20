class Solution {
public:
// we just need to make sure that there is one loosing state, don't care whose!
    bool f(int n, vector<int> &dp){
        if(n==0) return 0;

        if(dp[n]!=-1) return dp[n];

        for(int j=1;j*j<=n;j++){
            if(!f(n-j*j,dp)){
                dp[n]=1; return true;
            }
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};