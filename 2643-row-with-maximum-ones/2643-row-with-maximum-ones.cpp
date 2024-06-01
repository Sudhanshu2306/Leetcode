class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size(); int m=mat[0].size();
        int ind=INT_MAX; int count=INT_MIN;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) temp++;
            }
            if(temp>count){
                ind=i; count=temp;
            }
        }
        return {ind,count};
    }
};