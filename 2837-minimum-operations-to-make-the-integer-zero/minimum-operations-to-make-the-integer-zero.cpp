class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int n=0;
        long long x=num1, y=num2;
        while(num1>=0 && n<=60){
            int mini=__builtin_popcountll(x);

            if(n>=mini && n<=x) return n;
            n++; x-=y;
        }
        return -1;
    }
};