class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int maxi=INT_MIN;
                for(int l=i;l<i+3;l++){
                    for(int m=j;m<j+3;m++){
                        maxi=max(maxi,grid[l][m]);
                    }
                }
                ans[i][j]=maxi;
            }
        }
        return ans;
    }
};