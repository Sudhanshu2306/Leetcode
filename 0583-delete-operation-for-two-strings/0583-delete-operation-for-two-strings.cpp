class Solution {
public:
    
    int lcs(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j]=lcs(i-1,j-1,s1,s2,dp)+1;
        return dp[i][j]=max(lcs(i-1,j,s1,s2,dp),lcs(i,j-1,s1,s2,dp));
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.length(); int m=word2.length();
        vector<int> prev(m+1,0), curr(m+1,0);
        
        // int ans = lcs(n-1,m-1,word1,word2,dp);
        // return (n-ans)+(m-ans);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) curr[j] = prev[j-1]+1;
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        int ans = prev[m];
        return (n-ans) + (m-ans);
    }
};