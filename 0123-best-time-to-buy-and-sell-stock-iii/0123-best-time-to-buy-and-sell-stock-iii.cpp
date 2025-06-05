class Solution {
public:
    int f(vector<int> &a, int i, int buy, int t, vector<vector<vector<int>>> &dp){
        // base case
        if(t==0 || i==a.size()) return 0;

        if(dp[i][buy][t]!=-1) return dp[i][buy][t];

        int profit=0;
        if(buy==1) profit=max(f(a,i+1,0,t,dp)-a[i],f(a,i+1,1,t,dp));
        else profit=max(f(a,i+1,1,t-1,dp)+a[i],f(a,i+1,0,t,dp));

        return dp[i][buy][t]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,0,1,2,dp);
        
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