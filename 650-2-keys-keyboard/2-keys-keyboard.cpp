class Solution {
public:
int f(int i, int n, int x, vector<vector<int>> &dp){
    if(i==n) return 0;
    if(i>n) return n;

    // dp state is to get a particular number of A with last addition number
    if(dp[i][x]!=-1) return dp[i][x];

    int paste=1+f(i+x,n,x,dp);
    int copy=1e9;
    if(i!=x) copy=1+f(i,n,i,dp);
    return dp[i][x]=min(paste,copy);
}
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(1007,vector<int>(1007,-1));
        return 1+f(1,n,1,dp);
    }
};