class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int nop) {
        int maxi = *max_element(nums.begin(), nums.end());
        int n = maxi+k+2;
        vector<int> temp(n, 0);
        for (int num : nums) temp[num]++;
    
        vector<int> pre(n, 0);
        pre[0] = temp[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + temp[i];
    
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i] == 0 && nop == 0) continue;
            
            int y = min(n - 1, i + k);
            int x = max(0, i - k);
            int tot;
            if(x > 0) tot = pre[y] - pre[x-1];
            else tot = pre[y];
            
            int z = tot - temp[i];
            int total = temp[i] + min(nop, z);
            ans = max(ans, total);
        }
        return ans;
    }
};