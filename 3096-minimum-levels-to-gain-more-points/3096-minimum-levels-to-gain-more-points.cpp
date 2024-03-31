class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int n = p.size();
        vector<int> pre(n);
        
        if (p[0] == 0) {
            p[0] = -1;
        }
        
        pre[0] = p[0];
        
        for (int i = 1; i < n; i++) {
            if (p[i] == 0) {
                p[i] = -1;
            }
            pre[i] = p[i] + pre[i - 1];
        }
        
        for (int i = 0; i < n - 1; i++) {
            int ans = pre[i];
            int res = pre[n - 1] - pre[i];
            if (ans > res) {
                return i + 1;
            }
        }

        return -1;
    }
};