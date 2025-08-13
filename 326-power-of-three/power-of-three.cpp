class Solution {
public:
    // bool flag=false;
    bool f(int n){
        if(n<=0) return false;
        if(n==1) return true;

        if(n%3==0) return f(n/3);
        return false;
    }
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        return f(n);
    }
};