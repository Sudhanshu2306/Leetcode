class Solution {
public:
    vector<int> mini;
    int dp[13][1<<13];
    // i is the index that represents set1 points and mask represents that how many points are covered in set2
    int f(int i, int mask, vector<vector<int>> &cost){
        int n=cost.size(), m=cost[0].size();
        if(i==n){
            int x=0;
            for(int j=0;j<m;j++){
                if(!(mask&(1<<j))) x+=mini[j];
            }
            return x;
        }

        if(dp[i][mask]!=-1) return dp[i][mask];

        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,cost[i][j]+f(i+1,mask|(1<<j),cost));
        }
        return dp[i][mask]=ans;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n=cost.size(), m=cost[0].size();
        memset(dp,-1,sizeof(dp));
        mini.resize(m,INT_MAX);

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++) mini[j]=min(mini[j],cost[i][j]);
        }
        return f(0,0,cost);
    }
};