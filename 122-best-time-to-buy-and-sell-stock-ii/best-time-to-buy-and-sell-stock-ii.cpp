class Solution {
public:
    int f(vector<int> &a, int i, int buy, vector<vector<int>> &dp){
        if(i>=a.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy==0) profit=max(f(a,i+1,1,dp)-a[i],f(a,i+1,0,dp));
        else profit=max(f(a,i+1,0,dp)+a[i],f(a,i+1,1,dp));

        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return f(prices,0,0,dp);
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy==0) profit=max(dp[i+1][1]-prices[i],dp[i+1][0]);
                else profit=max(dp[i+1][0]+prices[i],dp[i+1][1]);
                dp[i][buy]=profit;
            }
        }
        return dp[0][0];
    }
};