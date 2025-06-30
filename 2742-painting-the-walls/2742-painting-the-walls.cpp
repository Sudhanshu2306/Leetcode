class Solution {
public:
    int dp[505][505];
    int f(int i, int k, vector<int> &cost, vector<int> &time){
        if(k<=0) return 0;
        if(i<0) return 1e9;

        if(dp[i][k]!=-1) return dp[i][k];

        int take=cost[i]+f(i-1,k-time[i]-1,cost,time);
        int nottake=f(i-1,k,cost,time);

        return dp[i][k]=min(take,nottake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        memset(dp,-1,sizeof(dp));

        return f(n-1,n,cost,time);
    }
};