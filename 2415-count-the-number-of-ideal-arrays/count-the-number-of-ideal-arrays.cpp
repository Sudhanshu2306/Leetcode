typedef long long ll;
ll mod=1e9+7;
ll f[100001]={};
class Solution {
public:
    ll power(ll a, ll b) {ll res = 1;while (b > 0) {if (b & 1)res = (res * a) % mod;a = (a * a) % mod;b = b >> 1;}return res;}
    ll fact(ll n){
        if(n==0) return 1; if(f[n]) return f[n]; f[n]=(n*fact(n-1))%mod; return f[n];
    }
    ll modinv(ll a, ll b){
        return (((fact(a)*power(fact(b),mod-2))%mod)*power(fact(a-b),mod-2))%mod;
    }
    int idealArrays(int n, int maxi) {
        vector<vector<int>> dp(100001,vector<int>(15,0));
        
        for(int i=1;i<=maxi;i++){
            dp[i][1]=1;
            for(int j=2;j*i<=maxi;j++){
                for(int k=1;k<min(n,14);k++){
                    dp[i*j][k+1]+=dp[i][k];
                }
            }
        }
        ll ans=0;
        for(int i=1;i<=maxi;i++){
            for(int j=1;j<=min(14,n);j++){
                ans=(ans+modinv(n-1,n-j)*dp[i][j])%mod;
            }
        }
        return ans;
    }
};