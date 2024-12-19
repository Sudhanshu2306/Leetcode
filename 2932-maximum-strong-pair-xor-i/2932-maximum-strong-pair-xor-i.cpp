class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxi=-1e9;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(abs(nums[i]-nums[j])<=min(nums[i],nums[j])){
                    maxi=max(maxi,nums[i]^nums[j]);
                }
            }
        }
        return maxi;
    }
};