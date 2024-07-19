class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rowMin;
        vector<int> colMax;
        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<m;j++){
                maxi=max(maxi,matrix[i][j]);
            }

            rowMin.push_back(maxi);
        }
        

    }
};