#define ll long long
class Solution {
public:
    void f(ll x, ll n, vector<ll> &factors, unordered_map<ll,ll> &mp){
        if(x>=1e11) return;
        if(n==0) return;
        if(mp[x]) return;
        factors.push_back(x);
        mp[x]=1;
        f(x*2LL,n-1,factors,mp);
        f(x*3LL,n-1,factors,mp);
        f(x*5LL,n-1,factors,mp);
    }
    int nthUglyNumber(int n) {
        vector<ll> fa;
        // vector<ll> dp(1e9,-1);
        unordered_map<ll,ll> mp;
        f(1,n,fa,mp);
        sort(fa.begin(),fa.end());
        return fa[n-1];
    }
};