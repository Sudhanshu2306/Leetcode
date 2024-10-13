class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        int i=0;
        for(auto it:nums){
            for(int j=0;j<it;j++) {
                if((j|(j+1))==it){
                    ans[i]=j;
                    break;
                }
            }
            i++;
        }
        return ans;
    }
};