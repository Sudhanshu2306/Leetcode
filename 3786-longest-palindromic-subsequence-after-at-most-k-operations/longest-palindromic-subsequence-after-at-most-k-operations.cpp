class Solution {
public:
    int f(int i, int j, int k, string &s, vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        if(i==j) return 1;

        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int x=0+f(i,j-1,k,s,dp);
        int y=0+f(i+1,j,k,s,dp);
        int d=min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
        int z=0;
        if(d<=k) z=2+f(i+1,j-1,k-d,s,dp);

        return dp[i][j][k]=max({x,y,z});

    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        int ans=f(0,n-1,k,s,dp);
        return ans;
    }
};