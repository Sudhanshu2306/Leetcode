class Solution {
public:
    int solve(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        // base case
        if(ind>=nums.size()) return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int pick=INT_MIN;
        if(prev==-1 || nums[ind]>nums[prev]) pick = 1 + solve(ind+1,ind,nums,dp);
        int notpick = solve(ind+1,prev,nums,dp) + 0;

        return dp[ind][prev+1] = max(pick, notpick);
        

    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }

};