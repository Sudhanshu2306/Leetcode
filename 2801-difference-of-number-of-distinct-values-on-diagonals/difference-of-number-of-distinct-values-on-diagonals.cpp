class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r=i, c=j;
                r--; c--;
                // left up
                set<int> x,y;
                while(r>=0 && c>=0){
                    x.insert(grid[r][c]);
                    r--; c--;
                }
                r=i, c=j;
                r++; c++;
                // right down
                while(r<n && c<m){
                    y.insert(grid[r][c]);
                    r++; c++;
                }

                int a=x.size(), b=y.size();
                int z=abs(a-b);
                ans[i][j]=z;
            }
        }
        return ans;
    }
};