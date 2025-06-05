class Solution {
public:
    
    bool solve(int i, int j, string s, string p, vector<vector<int>> &dp){
        // base case
        if(j<0 && i<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==p[j] || p[j]=='?') return dp[i][j] = solve(i-1,j-1,s,p,dp);
        else if(p[j]=='*'){
            bool ans=false;
            for(int k=0;k>=j;k++){
                ans |= solve(i,j-k,s,p,dp);
            }
            return dp[i][j]=ans;
        }
        else return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

        // Base case coversion
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)dp[i][0] = false;

        bool flag = true;
        for (int i = 1; i <= m; i++) {
            if (p[i - 1] != '*') {
                flag = false;
            }
            dp[0][i] = flag;
        }

        // Recursive relation conversion
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if (p[j - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};