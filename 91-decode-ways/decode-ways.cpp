class Solution {
public:
    int mod=1e9+7;
    int f(int i, string s, vector<int> &dp){
        if(i==s.size()) return 1;

        if(dp[i]!=-1) return dp[i];

        if(s[i]=='0') return dp[i]=0;
        int ans=f(i+1,s,dp);
        if(i<s.size()-1 && (s[i]=='1' || s[i]=='2' && s[i+1]<='6')) ans+=f(i+2,s,dp);

        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return f(0,s,dp);
    }
};