typedef long long ll;
class Solution {
public:
    ll f(ll i, ll j, int m, vector<int> &nums, vector<ll> &pre, vector<vector<ll>> &dp){
        if(j==0) return 0;
        if(i<0) return -1e18;
        if(dp[i][j]!=-1) return dp[i][j];

        ll ans=f(i-1,j,m,nums,pre,dp);
        for(int k=m;k<=i+1;k++){
            if(i-k+1>=0){
                ans=max(ans,pre[i+1]-pre[i-k+1]+f(i-k,j-1,m,nums,pre,dp));
            }
        }
        return dp[i][j]=ans;
    }
    int maxSum(vector<int>& nums, int k, int m) {
        ll n=nums.size();
        vector<ll> pre(n+1,0);
        for(ll i=1;i<=n;i++) pre[i]=pre[i-1]+nums[i-1];

        vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
        ll ans=f(n-1,k,m,nums,pre,dp);
        return ans;
    }
};