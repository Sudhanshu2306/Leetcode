class Solution {
public:
long long mod=1e9+7;

    long long power(long long n, long long x){
        long long ans=1;
        while(x>0){
            if(x%2==1)ans=(ans*n)%mod;

            n=(n*n)%mod;
            x/=2;
        }
        return ans;
    }

    int monkeyMove(int n) {
        
        long long x=power(2,n);
        long long ans=(x-2)%mod;
        
        return ans<0?mod+ans:ans;
    }
};