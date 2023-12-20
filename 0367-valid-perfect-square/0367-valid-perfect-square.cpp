class Solution {
public:
    bool isPerfectSquare(int num) {
        double a=sqrt(num);
        int b=sqrt(num);
        return a==b;
    }
};