class Solution {
public:
    
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=m || j2>=m)
            return -1e8;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+ grid[i][j2]; 
        }
        int maxi=-1e8;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2 =-1;dj2<=1;dj2++){
                int value=0;
                if(j1==j2) value=grid[i][j1];
                else value=grid[i][j1]+grid[i][j2];
                value+= solve(i+1,j1+dj1,j2+dj2,grid,n,m,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) {
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                } else {
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    long long maxi = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                long long value = 0;
                                if (j1 == j2) {
                                    value = grid[i][j1];
                                } else {
                                    value = grid[i][j1] + grid[i][j2];
                                }
                                value += dp[i + 1][nj1][nj2];
                                maxi = max(maxi, value);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};