class Solution {
public:
    int dp[301][301][11];

    int f(int ind, int prev, int d, vector<int>& nums) {
        if(d == 0) return 1e9;
        if(ind >= nums.size()) return d == 1 ? nums[prev] : 1e9;
        if(dp[ind][prev][d] != -1) return dp[ind][prev][d];

        // At each index, we have two option:
        // 1. Either carry the current task in previous day
        // 2. Finish the day and start current task in new day
        int carry = f(ind+1, nums[ind] > nums[prev] ? ind : prev, d, nums);
        int finish = nums[prev] + f(ind+1, ind, d-1, nums); // while finishing the day, we took maximum difficulty among all previous tasks 
        return dp[ind][prev][d] = min(carry, finish);
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        memset(dp, -1, sizeof(dp));
        return f(1, 0, d, jobDifficulty);
    }
};