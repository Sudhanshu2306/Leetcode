class Solution {
public:
    
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
        if(sum%2==1) return false;
        else sum/=2;
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,nums,dp);
    }
};