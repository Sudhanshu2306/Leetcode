class Solution {
public:
    // top down approach (recursion + memoisation)
    bool solve(int ind, int target, vector<int> & nums, vector<vector<int>> &dp){
        if(target==0) return true;
        
        if(ind==0) return (nums[0]==target);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notpick = solve(ind-1,target,nums,dp);
        bool pick=false;
        if(target>=nums[ind]) pick=solve(ind-1,target-nums[ind],nums,dp);
        
        return dp[ind][target] = pick | notpick;
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(n==1) return false;
        if(n==2) return (nums[0]==nums[1]);
        if(sum%2==1) return false;
        else sum/=2;
        
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        // return solve(n-1,sum,nums,dp);
        
        // base-case 
        for(int i=0;i<n;i++)
            dp[i][0] = true;
        
        dp[0][nums[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notpick=dp[i-1][target];
                bool pick=false;
                if(target>=nums[i]) pick=dp[i-1][target-nums[i]];
                
                dp[i][target]=pick || notpick;
            }
        }
        return dp[n-1][sum];
    }
};