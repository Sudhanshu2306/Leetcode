class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                int s=0,e=m-1;
                while(s<=e){
                    int mid=s+(e-s)/2;
                    if(matrix[i][mid]==target) return true;
                    else if(matrix[i][mid]<target) s=mid+1;
                    else e=mid-1;
                }
            }
        }
        return false;
    }
};