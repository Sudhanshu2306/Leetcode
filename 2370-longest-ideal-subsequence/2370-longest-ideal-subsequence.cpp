class Solution {
public:
    int dp[100005][26]; // prev
    int f(int i, int prev, string &s, int k){
        if(i>=s.size()) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take=0, nottake;
        if(prev==-1 || abs((s[i]-'a')-prev)<=k) take=1+f(i+1,s[i]-'a',s,k);
        nottake=f(i+1,prev,s,k);

        return dp[i][prev+1]=max(take,nottake);
    }
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));

        return f(0,-1,s,k);
    }
};