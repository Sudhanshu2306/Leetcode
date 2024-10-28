class Solution {
public:
    unordered_map<long long, int> memo;

    int solve(vector<int>& nums, int i, long long prev) {
        if (i == nums.size()) return 0;
        long long key = ((long long)i << 32) | prev;
        if (memo.find(key) != memo.end()) return memo[key];
        
        int a = solve(nums, i + 1, prev);
        int b = 0;
        if (prev == 1 || prev * prev == nums[i]) {
            b = max(solve(nums, i + 1, prev), 1 + solve(nums, i + 1, nums[i]));
        }
        return memo[key] = max(a, b);
    }
    
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        memo.clear();
        int res = solve(nums, 0, 1);
        return res == 1 ? -1 : res;
    }
};
