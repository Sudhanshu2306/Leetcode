class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int dp[201][201];
    int dfs(int i, int j, vector<vector<int>> &a){
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni>=0 && ni<a.size() && nj>=0 && nj<a[0].size() && a[i][j]<a[ni][nj]){
                dp[i][j]=max(dp[i][j],1+dfs(ni,nj,a));
            }
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        memset(dp,-1,sizeof(dp));
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ans=dfs(i,j,a);
                maxi=max(maxi,ans);
            }
        }
        return maxi;
    }
};