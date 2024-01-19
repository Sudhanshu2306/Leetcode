class Solution {
public:
    
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp){
        // base case
        if(i<0) return (j+1);
        if(j<0) return (i+1);
        
        if(dp[i][j]!=-1) return dp[i][j];
        // insert
        if(s[i]==t[j]) return solve(i-1,j-1,s,t,dp); 
        else {
            int x = solve(i,j-1,s,t,dp)+1;
            // delete
            int y = solve(i-1,j,s,t,dp)+1;
            // replace
            int z=solve(i-1,j-1,s,t,dp)+1;
            // computing mininum of all three

            return dp[i][j]=min(x,min(y,z));
        }
    }
    
    int minDistance(string s, string t) {
        int n=s.length(); int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};