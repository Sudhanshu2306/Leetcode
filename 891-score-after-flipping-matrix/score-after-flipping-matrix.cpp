class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    grid[i][j]=!grid[i][j];
                }
            }
        }

        for(int j=0;j<m;j++){
            int o=0,z=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1) o++;
                else z++;
            }
            if(z>o){
                for(int k=0;k<n;k++){
                    grid[k][j]=!grid[k][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=0;j<m;j++){
                x+=grid[i][j]*pow(2,m-j-1);
            }
            ans+=x;
        }
        return ans;
    }
};