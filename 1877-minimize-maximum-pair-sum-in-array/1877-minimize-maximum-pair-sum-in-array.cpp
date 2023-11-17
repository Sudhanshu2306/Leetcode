class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long n=nums.size();
        long long maxi=0;
        for(int i=0;i<(n/2);i++){
            if(maxi<(nums[i]+nums[n-i-1])){
                maxi=nums[i]+nums[n-i-1];
            }
        }
        return maxi;
    }
};