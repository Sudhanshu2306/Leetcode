#define ll long long
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        ll n=points.size();
        ll m=points[0].size();

        vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
        // first row
        for(int i=0;i<m;i++) dp[0][i]=points[0][i];
        // for remaining rows
        for(int i=1;i<n;i++){
            vector<ll> lm(m) ,rm(m);
            lm[0]=dp[i-1][0];
            for(int j=1;j<m;j++){
                lm[j]=max(dp[i-1][j],lm[j-1]-1);
            }

            rm[m-1]=dp[i-1][m-1];
            for(int j=m-2;j>=0;j--){
                rm[j]=max(dp[i-1][j],rm[j+1]-1);
            }

            for(int j=0;j<m;j++){
                dp[i][j]=points[i][j]+max(lm[j],rm[j]);
            }
        }
        ll ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,dp[n-1][i]);
        }
        return ans;
    }
};