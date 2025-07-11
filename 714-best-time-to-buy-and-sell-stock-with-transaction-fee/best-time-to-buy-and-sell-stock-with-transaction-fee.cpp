class Solution {
public:
    int f (int ind, int buy, int fee, vector<int>& prices, vector<vector<int>> &dp){
        // base case
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit;
        if(buy==1) profit = max(-prices[ind]+f(ind+1,0,fee,prices,dp), f(ind+1,1,fee,prices,dp));
        else profit = max(prices[ind]+f(ind+1,1,fee,prices,dp)-fee,f(ind+1,0,fee,prices,dp));

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return f(0,1,fee,prices,dp);

        double nextBuy, nextNotBuy, todayBuy, todayNotBuy;
        nextBuy = nextNotBuy = 0;
        for(int ind=n-1;ind>=0;ind--){
            todayBuy = max(-prices[ind] + nextNotBuy, nextBuy);
            todayNotBuy = max(prices[ind] + nextBuy-fee, nextNotBuy);
            nextBuy=todayBuy;
            nextNotBuy = todayNotBuy;
        }
        return (int)nextBuy;
    }
};