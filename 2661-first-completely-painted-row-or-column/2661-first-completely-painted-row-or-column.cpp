class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();

        map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int> r(n,0), c(m,0);
        for(auto i=0;i<arr.size();i++){
            auto [x,y]=mp[arr[i]];
            r[x]++; c[y]++;
            if(r[x]==m || c[y]==n) return i;
        }
        return -1;
    }
};