class Solution {
public:
    bool isPalindrome(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int f(int i, int j, string &s){
        if(i>=j) return 1;

        if(s[i]==s[j]) return f(i+1,j-1,s);
        return 0;
    }

    int memoization(int i, int j, string &s, vector<vector<int>> &dp){
        if(i>=j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = memoization(i+1,j-1,s,dp);
        return dp[i][j] = 0;        
    }

    int countSubstrings(string s) {
        int n=s.length();
        // return f(0,n-1,s);
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++) ans+=memoization(i,j,s,dp);
        }
        return ans;
    }
};