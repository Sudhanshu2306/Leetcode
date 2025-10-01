class Solution {
public:
    int numWaterBottles(int b, int n) {
        int ans=b;
        // ans+=b/n;
        int y;

        while(b>=n){
            y=b/n;
            ans+=y;
            b%=n; b+=y;
        }
        return ans;
    }
};