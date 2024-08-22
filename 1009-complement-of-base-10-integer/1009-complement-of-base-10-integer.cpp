class Solution {
public:
    int bitwiseComplement(int n) {
        int msb=0;
        int num=n;
        while(n>1){
            n=n>>1;
            msb+=1;
        }
        long long x=pow(2,msb+1)-1;
        return x-num;
    }
};