class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        int s=0,e=m-1;

        while(s<=e){
            int midC=s+(e-s)/2;
            int maxR=0;

            for(int i=0;i<n;i++){
                if(mat[i][midC]>mat[maxR][midC]) maxR=i;
            }
            int curr=mat[maxR][midC];
            int left=midC==0?-1:mat[maxR][midC-1];
            int right=midC==m-1?-1:mat[maxR][midC+1];

            if(curr>left && curr>right) return {maxR,midC};
            else if(curr<left) e=midC-1;
            else s=midC+1;
        }
        return {-1,-1};
    }
};