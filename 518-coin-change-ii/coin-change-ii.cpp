class Solution {
public:
    // total number of ... jab bhi hoga, we will addd the possible combinations
    int solve(int ind, int target, vector<int> &coins, vector<vector<long long>> &dp){
        
        if(ind==0) return (target%coins[0]==0);     
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notpick = solve(ind-1,target,coins,dp);
        int pick = 0;
        if(coins[ind]<=target) pick = solve(ind, target-coins[ind],coins,dp) ;
        
        return dp[ind][target] = pick+notpick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,-1));              
                              
        return solve(n-1,amount,coins,dp);
        
        // for(int i=0;i<=amount;i++){
        //     dp[0][i]=1LL*(i%coins[0]==0);
        // }
        
        // for(int i=1;i<n;i++){
        //     for(int target=0;target<=amount;target++){
        //         long long notpick = dp[i-1][target];
        //         long long pick = 0;
        //         if(coins[i]<=target) pick = dp[i][target-coins[i]] ;

        //         dp[i][target] = pick+notpick;
        //     }
        // }
        // // ye wahi return hota h jo hum memo waale function mein initially pass karte h
        // return dp[n-1][amount];
    }
};