class Solution {
public:
    int pivotInteger(int n) {
        // n(n+1)/2
        if(n==1) return 1;
        if(n>1 && n<8) return -1;

        for(int i=(n/2);i<n;i++){
            if((n*n)+n == 2*(i*i)) return i;
        }
        return -1;
    }
};