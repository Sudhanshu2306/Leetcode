class Solution {
public:
    int findComplement(int num) {
        int msb=0;
        int n=num;
        while(n>1){
            n=n>>1;
            msb+=1;
        }
        long long x=pow(2,msb+1)-1;
        return x-num;
    }
};