class Solution {
public:
int f(int i, int m, vector<int> &suf, vector<int> &piles, vector<vector<int>> &dp){
    int n=piles.size();
    if(i>=n) return 0;

    if(dp[i][m]!=-1) return dp[i][m];
    int maxi=-1e9;
    for(int j=1;j<=min(2*m,n-1);j++){
        int M=max(m,j);
        maxi=max(maxi,suf[i]-f(i+j,M,suf,piles,dp));
    }
    return dp[i][m]=maxi;
}
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        if(n==1) return piles[0]; 
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<int> suf(n);
        suf[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=piles[i]+suf[i+1];
        }
        return f(0,1,suf,piles,dp);
    }
};