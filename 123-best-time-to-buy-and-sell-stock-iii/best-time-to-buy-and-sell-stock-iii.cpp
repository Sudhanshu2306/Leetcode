class Solution {
public:
    int f(int i, int t, vector<int>& prices, int buy, vector<vector<vector<int>>> &dp){
        if(i>=prices.size() || t==0) return 0;

        if(dp[i][buy][t]!=-1) return dp[i][buy][t];

        int profit;
        if(buy==1){
            profit=max(f(i+1,t,prices,0,dp)-prices[i],f(i+1,t,prices,1,dp));
        }
        else{
            profit=max(f(i+1,t-1,prices,1,dp)+prices[i],f(i+1,t,prices,0,dp));
        }
        return dp[i][buy][t]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,2,prices,1,dp);
        
        // base case
        // we could have omitted base case, as all values are zero, but this is just for sense of understanding that how we write base case
        
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<2;buy++){
        //         for(int cap=1;cap<3;cap++){
        //             // buy
        //             if(buy==1) dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap] ,dp[ind+1][1][cap]);
        //             // sell
        //             else dp[ind][buy][cap] = max(prices[ind]+ dp[ind+1][1][cap-1] , dp[ind+1][0][cap]);
        //         }
        //     }
        // }
        // return dp[0][1][2];
    }
};