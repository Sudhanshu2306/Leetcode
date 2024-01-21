class Solution {
public:
    
    int recursion(int ind, vector<int>& nums, vector<int> &dp){
        // base case
        if(ind==0) return nums[0];
        
        if(ind<0) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int notpick = recursion(ind-1,nums,dp)+0;
        int pick = recursion(ind-2,nums,dp)+nums[ind];
        
        return dp[ind] = max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        // return recursion(n-1,nums,dp);
        
        // basecase
        dp[0]=nums[0];
        
        for(int i=1;i<n;i++){
            int pick;
            if(i>1) pick=dp[i-2] +nums[i];
            else pick = nums[i];
            int notpick = dp[i-1];
            
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};