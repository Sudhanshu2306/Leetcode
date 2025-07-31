class Solution {
public:
    int dp[201][201];
    int f(int start, int end){
        if(start>=end) return 0;

        if(dp[start][end]!=-1) return dp[start][end];

        int mini=1e9;
        for(int i=start;i<=end;i++){
            mini=min(mini,i+max(f(start,i-1),f(i+1,end)));
        }
        return dp[start][end]=mini;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));

        return f(1,n);
    }
};