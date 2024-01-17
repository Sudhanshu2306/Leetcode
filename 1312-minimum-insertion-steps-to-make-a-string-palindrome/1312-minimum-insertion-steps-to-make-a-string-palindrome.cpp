class Solution {
public:
    
    int solve(int i, int j, string s, string x, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if (s[i]==x[j]) return dp[i][j] = solve(i-1,j-1,s,x,dp) + 1;
        return dp[i][j] = max(solve(i,j-1,s,x,dp),solve(i-1,j,s,x,dp));
        
    }
    
    int longestPalindromeSubseq(string s) {
        string x=s;
        int n=s.length();
        reverse(s.begin(),s.end());
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solve(n-1,n-1,s,x,dp);
        
        vector<int> prev(n+1,0), curr(n+1,0);
        for(int i=0;i<=n;i++) prev[i]=0;
        // for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==x[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j]= max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n];
    }
    
    int minInsertions(string s) {
        int n=s.length();
        return n - longestPalindromeSubseq(s);
    }
};