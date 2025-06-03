class Solution {
public:
    int f(vector<int> &a, int i, int j, vector<vector<long long>> &dp){
        if(i>=j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        long long mini=INT_MAX;
        for(int k=i;k<=j-1;k++){
            long long ans=f(a,i,k,dp)+f(a,k+1,j,dp)+a[i-1]*a[k]*a[j];
            mini=min(ans,mini);
        }
        return dp[i][j]=mini;
    }
    int minScoreTriangulation(vector<int>& a) {
        int n=a.size();
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
        return f(a,1,n-1,dp);
    }
};