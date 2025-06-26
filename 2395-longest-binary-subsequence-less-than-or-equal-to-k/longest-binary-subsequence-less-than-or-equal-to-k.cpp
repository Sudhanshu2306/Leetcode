class Solution {
public:
    int dp[1001][1001];
    int f(int i, int len, string &s, int k){
        if(i<0) return 0;
        if(k<0) return 0;

        if(dp[i][len]!=-1) return dp[i][len];

        int nottake=f(i-1,len,s,k);
        int take=-1e9;
        if(k-(s[i]-'0')*pow(2,len)>=0) take=1+f(i-1,len+1,s,k-(s[i]-'0')*pow(2,len));

        return dp[i][len]=max(take,nottake);
    }
    int longestSubsequence(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        return f(n-1,0,s,k);
    }
};