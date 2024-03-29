class Solution {
public:
    
    int solve(int ind1,int ind2, string text1, string text2, vector<vector<int>> &dp){
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(text1[ind1]==text2[ind2]) return 1+solve(ind1-1,ind2-1,text1,text2,dp);
        return dp[ind1][ind2] = max(solve(ind1,ind2-1,text1,text2,dp),solve(ind1-1,ind2,text1,text2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(); int m=text2.length();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // return solve(n-1,m-1,text1,text2,dp);
        // shifting of index i.e 0->(-1)
        vector<int> prev(m+1,0), curr(m+1,0);
        for(int i=0;i<=m;i++) prev[i]=0;
        // for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j]= max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
};