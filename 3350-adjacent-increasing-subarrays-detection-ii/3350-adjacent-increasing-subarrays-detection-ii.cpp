class Solution {
public:

bool xx(vector<int>& nums, int k) {
    int n = nums.size();
    vector<bool> temp(n, false);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] < nums[i]) ans++;
        else ans = 0;
        
        if (ans >= k - 1) temp[i - k + 1] = true;
    }
    
    for (int i = 0; i <= n - 2 * k; ++i) {
        if (temp[i] && temp[i + k]) return true;
    }
    return false;
}
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n / 2;
        int ans = 1;
    
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (xx(nums, mid)) {
                ans = mid;   
                left = mid + 1; 
            } 
            else right = mid - 1; 
            
        }
        return ans;
    }
};