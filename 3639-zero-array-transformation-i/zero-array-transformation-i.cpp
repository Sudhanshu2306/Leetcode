class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> x(n+1,0);
        for(auto it:queries){
            int l=it[0], r=it[1];
            x[l]++; x[r+1]--;
        }
        for(int i=1;i<n;i++){
            x[i]+=x[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>x[i]) return false;
        }
        return true;
    }
};