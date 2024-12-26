class Solution {
public:
    // this question is same as finding number of subsets with given difference k
    // top down approach
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
    
        if(ind==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==nums[0] || target==0) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        int notpick=solve(ind-1,target,nums,dp);
        int pick=0;
        if(target>=nums[ind]) pick=solve(ind-1,target-nums[ind],nums,dp);
        
        return dp[ind][target] = pick+notpick;
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        // subset1 + subset2 = totalSum of vector elements 
        // and between subset1 - subset2 is given as target
        // so now if we calculate subset1 sum using simple linear equation
        
        int n=nums.size(); int sum=0;
        for(auto i:nums) sum+=i;
        
        sum+=abs(target);
        if(sum%2) return 0;
        else sum/=2;
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        return solve(n-1, sum, nums,dp);
        
        
    }
};