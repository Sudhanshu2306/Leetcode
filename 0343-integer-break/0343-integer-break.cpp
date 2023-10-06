class Solution {
public:
    int integerBreak(int n) {
        int maxp = 0;
        for (int k = 2; k <= n; k++) {
            int q = n / k;
            int r = n % k;
            int p = 1;

            for (int i = 0; i < k; i++) {
                if (i < r) {
                    p *= (q + 1);
                } else {
                    p *= q;
                }
            }
            maxp = max(maxp, p);
        }
        return maxp;
    }
};