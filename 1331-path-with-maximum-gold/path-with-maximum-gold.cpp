class Solution {
    int solve(vector<vector<int>>& grid, int i,int j){
        int n=grid.size();
        int m=grid[0].size();

        // base case
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) return 0;

        // mark the current position as zero! kyu? kyuki dobara visit nahi karna h!
        int x=grid[i][j];
        grid[i][j]=0;

        int d=solve(grid,i+1,j);
        int u=solve(grid,i-1,j);
        int l=solve(grid,i,j-1);
        int r=solve(grid,i,j+1);

        // backtrack
        grid[i][j]=x;

        return x+max({d,u,l,r});
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) maxi=max(maxi,solve(grid,i,j));
            }
        }
        return maxi;
    }
};