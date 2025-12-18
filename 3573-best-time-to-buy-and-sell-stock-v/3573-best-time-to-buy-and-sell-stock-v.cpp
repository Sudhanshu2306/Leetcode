typedef long long ll;
class Solution {
public:
    vector<vector<vector<ll>>> dp;
    ll f(ll i, ll x, int k, vector<int> &prices){
        if(i>=prices.size() || k==0){
            if(x==2) return -1e9;
            return 0;
        }

        if(dp[i][k][x] !=-1e9) return dp[i][k][x];

        ll ans=-1e9;

        if(x==0){
            ans=max({ans,f(i+1,1,k,prices)-prices[i],f(i+1,2,k,prices)+1LL*prices[i], f(i+1,0,k,prices)});
        }
        else if(x==1){
            ans=max({ans,f(i+1,x,k,prices), f(i+1,0,k-1,prices)+1LL*prices[i]});
        }
        else{
            ans=max({ans,f(i+1,x,k,prices), f(i+1,0,k-1,prices)-1LL*prices[i]});
        }

        return dp[i][k][x]=ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        dp.resize(n,vector<vector<ll>>(n/2+1,vector<ll>(3,-1e9)));

        return f(0,0,k,prices);
    }
};