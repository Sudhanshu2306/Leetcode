class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int y=__builtin_popcount(num2);

        int x=0;
        for(int i=31;i>=0 && y>0;i--){
            if(num1 & (1<<i)){
                x|=(1<<i); y--;
            }
        }
        if(y>0){
            for(int i=0;i<=31 && y>0;i++){
                if(!(x & (1<<i))){
                    x|=(1<<i);
                    y--;
                }
            }
        }
        return x;
    }
};