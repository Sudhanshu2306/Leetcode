class Solution {
public:
    int solve(vector<int> &nums, int ind, int p, vector<vector<int>> &dp){
        int n = nums.size();
        if (ind == n)
            return 0;
        if (dp[ind][p + 1] != -1) 
            return dp[ind][p + 1];

        int maxLen = 0 + solve(nums, ind + 1, p, dp);
        if (p == -1 || nums[ind] > nums[p])
            maxLen = max(maxLen, 1 + solve(nums, ind + 1, ind, dp));

        return dp[ind][p + 1] = maxLen;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(nums, 0, -1, dp);
    }

};