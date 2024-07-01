class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(k,1)); 
        
        // dp table
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                // calc the rem after mod with k
                // long long modVal=nums[i]%k+nums[j]%k;
                long long modVal=(nums[j]+nums[i])%k;
                // cout<<modVal<<" ";
                dp[i][modVal]=max(dp[i][modVal],dp[j][modVal]+1);
            }
        }
        
        int m=dp.size();
        
        // printing dp table for reference
        for(int i=0;i<m;i++){
            for(int j=0;j<dp[i].size();j++){
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        // maxi is the final answer 
        long long maxi=-1e9;
        
        // final answer is not on last box of dp grid, it can be anywhere
        for(int i=0;i<m;i++){
            for (int j=0;j<dp[i].size();j++) {
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi; 
    }

    
};