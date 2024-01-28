class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(); int m=matrix[0].size();
        // vector<vector<int>> pre(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }

        int count=0;
        for(int col1=0;col1<m;col1++){
            for(int col2=col1;col2<m;col2++){
                int sum=0;
                unordered_map<int,int> mp; mp[0]=1;
                for(int row=0;row<n;row++){
                    sum+=matrix[row][col2];
                    if(col1>0){
                        sum-=matrix[row][col1-1];
                    }
                    count+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};