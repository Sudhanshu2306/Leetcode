class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans+=((row[i]-1)*(col[j]-1));
                }
            }
        }
        return ans;
    }
};