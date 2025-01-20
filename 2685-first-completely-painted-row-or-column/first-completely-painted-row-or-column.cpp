class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(); int m=mat[0].size();

        vector<int> r(n,0); vector<int> c(m,0);
        map<int,pair<int,int>> mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<n*m;i++){
            int x=mp[arr[i]].first;
            int y=mp[arr[i]].second;
            r[x]++; c[y]++;
            if(r[x]==m || c[y]==n) return i;
        }
        return 0;
    }
};