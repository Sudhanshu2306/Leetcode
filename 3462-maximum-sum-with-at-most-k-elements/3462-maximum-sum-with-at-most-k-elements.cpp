class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<pair<int,int>> x;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
                x.push_back({grid[i][j],i});
        }
        sort(x.rbegin(),x.rend());
        int c=0;
        long long sum=0;
        vector<int> count(grid.size(),0);
        for(auto &[y,z]:x){
            if(count[z]<limits[z] && c<k){
                sum+=y; count[z]++; c++;
            }
        }
        return sum;
    }
};