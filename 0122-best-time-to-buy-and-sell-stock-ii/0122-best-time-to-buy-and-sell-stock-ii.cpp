class Solution {
public:
    // there is variable buy as a flag variable so that to tract wether we can buy that item or not at that index
    // one more thing to remeber is that in this question we'll start the recursion also with bottom up
    int f (int ind, int buy, vector<int>& prices, vector<vector<int>> &dp){
        // base case
        if(ind==prices.size()) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit;
        // buy
        if(buy==1) profit = max(-prices[ind] + f(ind+1,0,prices,dp), f(ind+1,1,prices,dp));
        // sell
        else profit = max(prices[ind]+ f(ind+1,1,prices,dp), f(ind+1,0,prices,dp));
        
        return dp[ind][buy] = profit;
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        // return f(0,1,prices,dp);
        
        // base case
        // already all index elements are zero;
        
        
        double nextBuy, nextNotBuy, todayBuy, todayNotBuy;
        nextBuy = nextNotBuy = 0;
        for(int ind=n-1;ind>=0;ind--){
            todayBuy = max(-prices[ind] + nextNotBuy, nextBuy);
            
            todayNotBuy = max(prices[ind] + nextBuy, nextNotBuy);
            
                
            nextBuy=todayBuy;
            nextNotBuy = todayNotBuy;
        }
        return (int)nextBuy;
    }
};