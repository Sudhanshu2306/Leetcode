class Solution {
public:
int ff(int num) {
    int product = 1;
    while (num > 0) {
        int digit = num % 10;
        product *= digit;
        num /= 10;
    }
    return product;
}
    int smallestNumber(int n, int t) {
        while (true) {
            int product = ff(n);
            if (product % t == 0) {
                return n;
            }
            n++;
        }
    }
};