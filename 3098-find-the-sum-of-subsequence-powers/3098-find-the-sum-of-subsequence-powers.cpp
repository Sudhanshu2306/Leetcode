class Solution {
public:
    int mod = (int)1e9 + 7;

    int f(vector<int>& nums, int k, int ind, int diff, int prevInd, unordered_map<long long, int> dp) {
        if (k == 0) {
            return diff;
        }

        if (ind >= nums.size())
            return 0;

        if(dp.find(diff)!=dp.end()) return dp[ind];

        int notpick = f(nums, k, ind + 1, diff, prevInd, dp);
        int pick = 0;

        if (prevInd == 0) {
            pick = f(nums, k - 1, ind + 1, diff, ind + 1, dp);
        } else
            pick = f(nums, k - 1, ind + 1,
                     min(diff, nums[ind] - nums[prevInd - 1]), ind + 1, dp);

        return dp[diff] = (pick % mod + notpick % mod) % mod;
    }

    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<long long, int> dp;
        return f(nums, k, 0, INT_MAX, 0, dp);
    }
};
