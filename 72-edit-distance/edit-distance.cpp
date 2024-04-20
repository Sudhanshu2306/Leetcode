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
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        vector<int> prev(m+1,0), curr(m+1,0);
        // return solve(n-1,m-1,s,t,dp);
        
        // base case
        for(int i=0;i<=m;i++) dp[0][i]=(i);
        for(int i=0;i<=n;i++) dp[i][0]=(i);
        
        for(int i=0;i<=m;i++) prev[i]=i;
        curr[0]=1;
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j] = prev[j-1];
                else{
                    int x = curr[j-1];
                    int y = prev[j];
                    int z= prev[j-1];
                    
                    curr[j] = 1 + min(x,min(y,z));
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};