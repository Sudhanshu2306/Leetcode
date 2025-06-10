class Solution {
public:
    
    int f(int i, int tar, vector<int> &a, vector<vector<int>> &dp){
        if(tar<0) return 1e9;
        if(i==0){
            if(tar%a[i]==0) return tar/a[i];
            else return 1e9;
        }
        if(dp[i][tar]!=-1) return dp[i][tar];

        int not_take=f(i-1,tar,a,dp);
        int take=1e9;
        if(a[i]<=tar) take=1+f(i,tar-a[i],a,dp);

        return dp[i][tar]=min(take,not_take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        // vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        
        // for(int x=0;x<=amount;x++) {
        //     if(x%coins[0]==0) dp[0][x] = x/coins[0];
        //     else dp[0][x]=1e9;
        // }
        
        // for(int i=1;i<n;i++){
        //     for(int t=0;t<=amount;t++){
        //         long long notpick = dp[i-1][t] + 0;
        //         long long pick = 1e9;
        //         if(coins[i]<=t) pick = 1 + dp[i][t-coins[i]];

        //         dp[i][t] = min(pick,notpick);
        //     }
        // }
        // long long ans = dp[n-1][amount];
        // if(ans>=1e9) return -1;
        else return ans;
    }
};