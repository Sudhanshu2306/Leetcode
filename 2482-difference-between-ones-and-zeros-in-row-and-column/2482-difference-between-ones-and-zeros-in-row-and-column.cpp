class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),0));
        vector<int> row(grid.size());
        vector<int> col(grid[0].size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    row[i]+=grid[i][j];
                    col[j]+=grid[i][j];
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans[i][j]=(2*row[i]-grid.size())+(2*col[j]-grid[0].size());
            }
        }
        return ans;
    }
};