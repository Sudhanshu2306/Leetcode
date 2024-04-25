class Solution {
public:

    int f(string &s, int k, int i, int prev, vector<vector<int>> &dp){
        if(i>=s.size()) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int pick=0,notpick=0;

        if(prev==-1 || abs((int)s[i]-prev-'a')<=k) pick=1+f(s,k,i+1,s[i]-'a',dp);
        if(prev==-1) notpick=f(s,k,i+1,-1,dp);
        else notpick= f(s,k,i+1,prev,dp);

        return dp[i][prev+1]=max(pick,notpick);
    }

    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(27,-1));
        return f(s,k,0,-1,dp);
    }
};