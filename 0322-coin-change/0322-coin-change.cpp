class Solution {
public:
    
    int solve(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(ind==0){
            if(target%coins[ind]==0) return target/coins[ind];
            else return 1e8;
        }
        if(dp[ind][target] !=-1) return dp[ind][target];
        int notpick = solve(ind-1,target,coins,dp) + 0;
        int pick = 1e8;
        if(coins[ind]<=target) pick = 1 + solve(ind,target-coins[ind],coins,dp);
        
        return dp[ind][target] = min(pick,notpick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // int ans = solve(n-1,amount,coins,dp);
        // if(ans>=1e8) return -1;
        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        
        for(int x=0;x<=amount;x++) {
            if(x%coins[0]==0) dp[0][x] = x/coins[0];
            else dp[0][x]=INT_MAX;
        }
        
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                long long notpick = dp[i-1][t] + 0;
                long long pick = INT_MAX;
                if(coins[i]<=t) pick = 1 + dp[i][t-coins[i]];

                dp[i][t] = min(pick,notpick);
            }
        }
        long long ans = dp[n-1][amount];
        if(ans>=INT_MAX) return -1;
        else return ans;
    }
};