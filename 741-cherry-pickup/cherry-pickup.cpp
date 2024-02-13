class Solution {
public:
    // int ans=0;
    int f(int i1, int j1, int i2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if(i1<0 || j1<0 || i2<0 || (i1+j1-i2)<0 || grid[i1][j1]==-1 || grid[i2][i1+j1-i2]==-1) return -1e8;
        // only r1 and c1 case bcoz they both reach at the same time
        if(i1==0 && j1==0) {
            return grid[i1][j1];
        }
        if(i2==0 && j1+i1-i2==0) {
            return grid[i2][j1+i1-i2];
        }
        if(dp[i1][j1][i2]!=0) return dp[i1][j1][i2];
        int ans=0;

        if(i1==i2 && j1==i1+j1-i2) ans+=grid[i1][j1];
        else ans+=(grid[i1][j1]+grid[i2][i1+j1-i2]);

        int a1=f(i1,j1-1,i2,grid,dp); //left and left
        int a2=f(i1-1,j1,i2,grid,dp); //up and left
        int a3=f(i1-1,j1,i2-1,grid,dp); //up and up
        int a4=f(i1,j1-1,i2-1,grid,dp); //left and up

        ans+=max(max(a1,a2),max(a3,a4));
        return dp[i1][j1][i2]=ans;;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,0)));
        int ans = f(n-1,n-1,n-1,grid,dp);
        return ans>=0?ans:0;
    }
};