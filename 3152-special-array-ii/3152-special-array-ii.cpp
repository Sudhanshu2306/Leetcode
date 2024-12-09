class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<bool> ans(m);
        int n=nums.size();

        vector<int> pre(n);
        int i=0;
        bool prev=(nums[0]%2!=0);
        for(int j=0;j<n;j++){
            if(nums[j]%2 != prev){
                prev=!prev;
            }
            else{
                for(int k=i;k<j;k++) pre[k]=j-1;
                i=j;
            }
        }
        for(int k=i;k<n;k++) pre[k]=(n-1);

        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            ans[i]=(pre[l]>=r);
        }
        return ans;
    }
};