class Solution {
public:
    map<string,int>m;
    int solve(int i,string &s,vector<int>&dp){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        int ans=1e9;
        ans=1+solve(i+1,s,dp);
        string k="";
        for(int j=i;j<s.size();j++){
            k+=s[j];
            if(m[k]>0){
                ans=min(ans,solve(j+1,s,dp));
            }
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& d) {
        for(auto i:d) m[i]++;
        vector<int>dp(s.size(),-1);
        return solve(0,s,dp);
    }
};