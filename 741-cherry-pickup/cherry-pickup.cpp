class Solution {
public:
    // int ans=0;
    int f(int i1, int j1, int i2, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
        if (i1 < 0 || j1 < 0 || i2 < 0 || (i1 + j1 - i2) < 0 ||
            grid[i1][j1] == -1 || grid[i2][i1 + j1 - i2] == -1)
            return -1e8;
        // only r1 and c1 case bcoz they both reach at the same time
        if (i1 == 0 && j1 == 0) {
            return grid[i1][j1];
        }
        if (i2 == 0 && j1 + i1 - i2 == 0) {
            return grid[i2][j1 + i1 - i2];
        }
        if (dp[i1][j1][i2] != 0)
            return dp[i1][j1][i2];
        int ans = 0;

        if (i1 == i2 && j1 == i1 + j1 - i2)
            ans += grid[i1][j1];
        else
            ans += (grid[i1][j1] + grid[i2][i1 + j1 - i2]);

        int a1 = f(i1, j1 - 1, i2, grid, dp);     // left and left
        int a2 = f(i1 - 1, j1, i2, grid, dp);     // up and left
        int a3 = f(i1 - 1, j1, i2 - 1, grid, dp); // up and up
        int a4 = f(i1, j1 - 1, i2 - 1, grid, dp); // left and up

        ans += max(max(a1, a2), max(a3, a4));
        return dp[i1][j1][i2] = ans;
        ;
    }

    int tabulation(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n, 0)));

        dp[0][0][0] = grid[0][0];

        for(int r1=0;r1<n;r1++){
            for(int c1=0;c1<n;c1++){
                for(int r2=0;r2<n;r2++){
                    int ans = 0;
                    if(r1==0 && c1==0 && r2==0){
                        dp[r1][c1][r2] = grid[r1][c1];
                    }
                    else if(grid[r1][c1]==-1 || grid[r2][r1+c1-r2]==-1){
                        dp[r1][c1][r2] = -1e8;
                    }
                    else{
                        ans = grid[r1][c1] + grid[r2][r1+c1-r2];
                        if(r1==r2 || c1==r1+c1-r2)    
                            ans = grid[r2][r1+c1-r2];

                        int a1 = (r1>0 && r2>0) ? dp[r1-1][c1][r2-1]:-1e8;
                        int a2 = (r1>0 && r1+c1-r2>0) ? dp[r1-1][c1][r2]:-1e8;
                        int a3 = (c1>0 && r2>0) ? dp[r1][c1-1][r2-1]:-1e8;
                        int a4 = (c1>0 && r1+c1-r2>0) ? dp[r1][c1-1][r2]:-1e8;

                        dp[r1][c1][r2] = ans + max({a1,a2,a3,a4});
                    }
                }
            }
        }
        return max(0,dp[n-1][n-1][n-1]);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n, 0)));
        int ans = f(n - 1, n - 1, n - 1, grid, dp);
        return ans >= 0 ? ans : 0;
    }
};