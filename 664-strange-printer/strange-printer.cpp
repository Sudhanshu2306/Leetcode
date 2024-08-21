class Solution {
public:
    int f(string &s,int i,int j,vector<vector<int>>&dp){
        if(i==j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=1e9;
        for(int k=i;k<j;k++){
            int left=f(s,i,k,dp);
            int right=f(s,k+1,j,dp);
            mini=min(mini,left+right);
        }
        return dp[i][j]=(s[i]==s[j])?mini-1:mini;
    }

    int strangePrinter(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(s,0,n-1,dp);
    }
};