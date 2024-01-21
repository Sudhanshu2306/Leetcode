class Solution {
public:
    int f (int ind, int buy,int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
    // base case
        if(ind==prices.size() || cap==0) return 0;
        
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit;
        // buy
        if(buy==1) profit = max(-prices[ind] + f(ind+1,0,cap,prices,dp), f(ind+1,1,cap,prices,dp));
        // sell
        else profit = max(prices[ind]+ f(ind+1,1,cap-1,prices,dp), f(ind+1,0,cap,prices,dp));
        
        return dp[ind][buy][cap] = profit;
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // return f(0,1,2,prices,dp);
        
        // base case
        // we could have omitted base case, as all values are zero, but this is just for sense of understanding that how we write base case
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<3;cap++){
                    // buy
                    if(buy==1) dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap] ,dp[ind+1][1][cap]);
                    // sell
                    else dp[ind][buy][cap] = max(prices[ind]+ dp[ind+1][1][cap-1] , dp[ind+1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
    }
};