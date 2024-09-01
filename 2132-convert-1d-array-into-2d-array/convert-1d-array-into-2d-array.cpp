class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        vector<vector<int>> ans;
        if(n*m!=o.size()) return ans;
        for(int i=0;i<o.size();i+=n){
            vector<int> x;
            for(int j=0;j<n;j++){
                x.push_back(o[i+j]);
            }
            ans.push_back(x);
        }
        return ans;
    }
};