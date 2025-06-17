typedef long long ll;
class Solution {
public:
    ll mod=1e9+7;
    vector<ll> fact,infact;
    ll powMod(ll a, ll b){
        ll res=1;
        while(b){
            if(b&1) res=(res*a)%mod;
            a=(a*a)%mod;
            b/=2;
        }
        return res;
    }
    ll nCr(ll n, ll r){
        // return fact[n]*powMod(fact[r],mod-2)%mod*powMod(fact[n-r],mod-2)%mod;
        return fact[n]*infact[r]%mod*infact[n-r]%mod;
    }
    int countGoodArrays(int n, int m, int k) {
        if(k>=n) return 0;
        fact.resize(n+1,1);
        for(int i=1;i<=n;i++) fact[i]=(i*fact[i-1])%mod;
        infact.resize(n+1);
        infact[n]=powMod(fact[n],mod-2);
        for(int i=n-1;i>=0;i--) infact[i]=infact[i+1]*(i+1)%mod;
        ll ans=m;
        ans=(ans*nCr(n-1,k))%mod;
        ans=(ans*powMod(m-1,n-k-1))%mod;
        return ans;
    }
};