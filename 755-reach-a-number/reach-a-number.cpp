class Solution {
public:
    int reachNumber(int target) {
        int k=abs(target);
        long long x=1;
        while(!(k<=x*(x+1)/2 && (k&1)==((x*(x+1)/2)&1))) x++;

        return x;
    }
};