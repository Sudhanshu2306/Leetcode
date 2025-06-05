class Solution {
public:

    int f(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp){
        // base case
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit;
        if(buy==1) profit=max(-prices[ind]+f(ind+1,0,prices,dp), f(ind+1,1,prices,dp));
        else profit=max(prices[ind]+f(ind+2,1,prices,dp),f(ind+1,0,prices,dp));

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return f(0,1,prices,dp);
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int i=n+1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(i>=n) dp[i][buy]=0;
                else{
                    if(buy==1) profit=max(-prices[i]+dp[i][0], dp[i+1][1]);
                    else profit=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};