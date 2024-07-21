class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> diff(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            diff[i] = target[i] - nums[i];
        }
        
        long long ans = abs(diff[0]);
        int prev = abs(diff[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if ((diff[i - 1] > 0 && diff[i] > 0) || (diff[i - 1] < 0 && diff[i] < 0)) {
                int add = abs(diff[i]) - abs(prev);
                if (add > 0) {
                    ans += add;
                }
            } 
            else {
                ans += abs(diff[i]);
            }
            prev = diff[i];
        }
        return ans;
    }
};