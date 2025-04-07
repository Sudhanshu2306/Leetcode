class Solution {
public:
    // top down approach (recursion + memoisation)
    bool solve(int i, int x, vector<int> & nums, vector<vector<int>> &dp){
        if(x==0) return true;
        if(i==nums.size()-1) return (nums.back()==x);
        
        if(dp[i][x]!=-1) return dp[i][x];

        bool notpick=solve(i+1,x,nums,dp);
        bool pick=false;
        if(x>=nums[i]) pick=solve(i+1,x-nums[i],nums,dp);
        
        return dp[i][x]=pick|notpick;
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return false;
        if(n==2) return (nums[0]==nums[1]);
        int sum=accumulate(nums.begin(), nums.end(),0);
        
        if(sum%2==1) return false;
        else sum/=2;
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,sum,nums,dp);
    }
};