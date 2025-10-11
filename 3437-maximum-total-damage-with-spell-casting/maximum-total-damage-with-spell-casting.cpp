class Solution {
public:
typedef long long ll;
    map<ll,ll> mp;
    vector<ll> dp;
    vector<ll> prev;
    ll f(int i, vector<ll> &a){
        if(i>=a.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        ll nottake=f(i+1,a);
        ll take=1LL*mp[a[i]]*a[i];

        if(prev[i]!=-1) take+=f(prev[i],a);

        return dp[i]=max(take,nottake);
    }
    long long maximumTotalDamage(vector<int>& power) {
        mp.clear();
        dp.clear();
        prev.clear();
        for(auto it:power){
            mp[it]++;
        }
        vector<ll> a;
        for(auto it:mp) a.push_back(it.first);
        ll n=a.size();
        prev.resize(n,-1);
        int j=-1;
        for(int i=0;i<n;i++){
            while(j+1<i && a[j+1]<=a[i]-3) j++;
            prev[i]=j;
        }
        // dp.resize(n+1,-1);

        vector<ll> dp(n,0);
        for(int i=0;i<n;i++){
            ll take=1LL*mp[a[i]]*a[i];
            if(prev[i]!=-1) take+=dp[prev[i]];
            ll nottake=(i>0?dp[i-1]:0);
            dp[i]=max(take,nottake);
        }

        return dp[n-1];
    }
};