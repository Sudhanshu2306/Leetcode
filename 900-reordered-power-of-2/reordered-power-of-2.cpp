class Solution {
public:
    int f(int n){
        long long ans=0;
        while(n){
            ans+=pow(10,n%10);
            n/=10;
        }
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        long long x=0;
        while(n){
            x+=pow(10,n%10);
            n/=10;
        }
        for(int i=0;i<32;i++){
            if(f(1<<i)==x) return true;
        }
        return false;
    }
};