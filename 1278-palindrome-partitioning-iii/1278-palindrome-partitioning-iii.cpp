class Solution {
public:
    int palindromeCost(int i, int j, string &s){
        int count=0;
        while(i<j){
            if(s[i]!=s[j]) count++;
            i++; j--;
        }
        return count;
    }
    int f(string s, int i, int k, vector<vector<int>> &dp){
        // base case
        if(k==0) return palindromeCost(i,s.size()-1,s);
        if(i>=s.size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];

        int mini=1e9;

        for(int j=i;j<s.size()-1;j++){
            int ans=palindromeCost(i,j,s)+f(s,j+1,k-1,dp);
            mini=min(mini,ans);
        }
        return dp[i][k]=mini;
    }
    int palindromePartition(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return f(s,0,k-1,dp);
    }
};