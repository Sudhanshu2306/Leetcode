class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n,INT_MAX);
        dp[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> temp=dp;
            for(auto it:flights){
                if(dp[it[0]]==INT_MAX) continue;
                temp[it[1]]=min(dp[it[0]]+it[2],temp[it[1]]);
            }
            dp=temp;
        }
        return dp[dst]==INT_MAX?-1:dp[dst];
    }
};