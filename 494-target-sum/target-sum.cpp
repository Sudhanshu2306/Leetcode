class Solution {
public:
    // this question is same as finding number of subsets with given difference k
    // top down approach
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
    
        if(ind>=nums.size()){
            if(target==0) return 1;
            return 0;
        }
        
        if(dp[ind][target+1000] != -1) return dp[ind][target+1000];
        int neg=solve(ind+1,target-nums[ind],nums,dp);
        int pos=solve(ind+1,target+nums[ind],nums,dp);
        
        return dp[ind][target+1000] = neg+pos;
        
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
        
        vector<vector<int>> dp(n,vector<int>(3000+1,-1));
        
        return solve(0, target, nums ,dp);
        
        
    }
};