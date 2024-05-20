class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans|=nums[i];
        }

        return ans*(1<<(n-1));
    }
};