class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &it:mp){
            if(it.first<0) sort(it.second.begin(),it.second.end());
            else sort(it.second.rbegin(),it.second.rend());
        }
        map<int,int> x;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=mp[i-j][x[i-j]++];
            }
        }
        return grid;
    }
};