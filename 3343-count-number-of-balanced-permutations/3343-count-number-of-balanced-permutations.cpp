typedef long long ll;
class Solution {
public:
    ll mod=1e9+7;
    ll exp(ll a, ll b){
        ll res=1;
        while(b){
            if(b&1){
                res=(1LL*res*a)%mod;
            }
            b>>=1; a=(1LL*a*a)%mod;
        }
        return res;
    }
    int countBalancedPermutations(string num) {
        vector<ll> cnt(10,0);
        ll sum=0;
        for(auto it:num){
            cnt[it-'0']++;
            sum+=(it-'0');
        } 
        if(sum%2==1) return 0;
        ll n=num.size();
        ll even=n/2,odd=(n+1)/2;
        vector<ll> fact(n+1,1), invfact(n+1,1);
        

        for(ll i=1;i<=n;i++){
            fact[i]=(1LL*i*fact[i-1])%mod;
            invfact[i]=exp(fact[i],mod-2);
        }
        ll count=(1LL*fact[n/2]*fact[(n+1)/2])%mod;
        vector<vector<vector<ll>>> dp(10, vector<vector<ll>>(n/2+1, vector<ll>(sum+1,-1)));
        auto f=[&](ll number, ll taken, ll currentSum, auto &&self)->ll{
            if(number==10){
                return (currentSum == sum/2 && taken==n/2 ? count:0);
            }

            if(dp[number][taken][currentSum]!=-1) return dp[number][taken][currentSum];

            long long ways=0;

            for(ll i=0;i<=min(cnt[number], (ll) n/2-taken);i++){
                ways=(ways+(1LL*(1LL*invfact[i]*invfact[cnt[number]-i])%mod*
                        self(number+1,taken+i,currentSum+i*number,self))%mod)%mod;
            }

            return dp[number][taken][currentSum]=ways;
        };

        return f(0,0,0,f);
    }
};