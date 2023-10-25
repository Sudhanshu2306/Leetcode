class Solution {
public:
    int kthGrammar(int n, int k) {
        bool flag = true; 

        int x = pow(2, n);

        while (x != 1) {
            x /= 2;
            if (k > x) {
                k -= x;
                flag = !flag;
            }
        }
        return ((flag) ? 0 : 1) ;
    }
};