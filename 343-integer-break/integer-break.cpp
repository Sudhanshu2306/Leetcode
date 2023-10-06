class Solution {
public:
    int integerBreak(int n) {
        int maxProduct = 0;
        for (int k = 2; k <= n; k++) {
            int quotient = n / k;
            int remainder = n % k;
            int product = 1;

            for (int i = 0; i < k; i++) {
                if (i < remainder) {
                    product *= (quotient + 1);
                } else {
                    product *= quotient;
                }
            }
            maxProduct = max(maxProduct, product);
        }
        return maxProduct;
    }
};