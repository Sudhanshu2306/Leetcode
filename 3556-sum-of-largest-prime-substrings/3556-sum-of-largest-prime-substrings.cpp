class Solution {
public:
    bool isPrime(long long n){
        if(n<2) return false;
        for(long long i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        vector<long long> z;
        int n=s.size();
        for(long long i=0;i<n;i++){
            long long x=0;
            for(long long j=i;j<n;j++){
                x=x*10+(s[j]-'0');
                if(isPrime(x)) z.push_back(x);
            }
        }
        sort(z.rbegin(),z.rend());
        z.erase(unique(z.begin(),z.end()),z.end());
        long long sum=accumulate(z.begin(),z.end(),0LL);
        if(z.size()>=3) return z[0]+z[1]+z[2];
        else return sum;
    }
};