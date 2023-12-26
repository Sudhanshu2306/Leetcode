class Solution {
public:
    
    long long recursion(int dice, int faces, int target){
        if(target<0)
            return 0;
        if(dice==0 & target!=0)
            return 0;
        if(target==0 &&dice!=0)
            return 0;
        if(target==0 && dice==0)
            return 1;
        long long ans=0;
        for(int i=1;i<=faces;i++){
            ans+=recursion(dice-1,faces,target-i);
        }
        return ans;
    }
    
    long long dpMemo(int dice, int faces, int target, vector<vector<long long>>& dp){
        int mod=1e9+7;
        if(target<0)
            return 0;
        if(dice==0 & target!=0)
            return 0;
        if(target==0 &&dice!=0)
            return 0;
        if(target==0 && dice==0)
            return 1;
        
        if(dp[dice][target]!=-1)
            return dp[dice][target]%mod;
        long long ans=0;
        for(int i=1;i<=faces;i++){
            ans+=dpMemo(dice-1,faces,target-i,dp)%mod;
        }
        return dp[dice][target]=ans%mod;
    }
    
    long long numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1));
        return dpMemo(n,k,target,dp);
    }
};