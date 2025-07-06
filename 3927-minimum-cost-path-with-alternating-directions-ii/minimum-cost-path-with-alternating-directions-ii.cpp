typedef long long ll;
class Solution {
public:
    vector<vector<vector<ll>>> dp;
    int x,y;
    ll f(int i, int j, int flag, vector<vector<int>> &a){
        if(i>=x || j>=y) return 1e18;
        if(i==x-1 && j==y-1) return 0;

        if(dp[i][j][flag]!=-1) return dp[i][j][flag];

        ll cost=0;
        if(flag){
            ll right=1e18,down=1e18;
            if(i+1<x) down=(1LL*(i+2)*(j+1))+f(i+1,j,0,a);
            if(j+1<y) right=(1LL*(i+1)*(j+2))+f(i,j+1,0,a);
            cost=min(right,down);
        }
        else{
            cost=a[i][j]+f(i,j,1,a);
        }
        return dp[i][j][flag]=cost;
    }
    long long minCost(int n, int m, vector<vector<int>>& waitCost) {
        dp.resize(n,vector<vector<ll>>(m,vector<ll>(2,-1))); 
        x=n,y=m;
        return f(0,0,1,waitCost)+1;
    }
};