class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> prev(m,0); vector<int> curr(m);
        for(int i=0;i<m;i++) curr[i]=grid[0][i];

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0;
                if(j>0) sum+=curr[j-1];
                if(i>0) sum+=prev[j];

                if(i>0 && j>0) sum-=prev[j-1];

                sum+=grid[i][j];
                curr[j]=sum;
                if(sum<=k) ans++;
            }
            prev=curr;
        }
        return ans;
    }
};