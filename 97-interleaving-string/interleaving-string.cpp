class Solution {
public:
    int dp[105][105];
    bool f(string &s1, string &s2, string &s3, int i, int j, int k){
        if(i<0 && j<0 && k<0) return true;
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
        bool ans=false;
        if(i>=0 && s1[i]==s3[k] && j>=0 && s2[j]==s3[k]) ans=f(s1,s2,s3,i-1,j,k-1) || f(s1,s2,s3,i,j-1,k-1);
        else if(i>=0 && s1[i]==s3[k]) ans=f(s1,s2,s3,i-1,j,k-1);
        else if(j>=0 && s2[j]==s3[k]) ans=f(s1,s2,s3,i,j-1,k-1);

        return dp[i+1][j+1]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size(),x=s3.size();
        if(x!=(n+m)) return false;
        memset(dp,-1,sizeof(dp));

        return f(s1,s2,s3,n-1,m-1,x-1);
    }
};