class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return matrix;
        }

        vector<vector<int>> ans = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> maxi(n, INT_MIN);

        for(int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                maxi[j] = max(maxi[j], matrix[i][j]);
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == -1) {
                    ans[i][j] = maxi[j];
                }
            }
        }

        return ans;
    }
};