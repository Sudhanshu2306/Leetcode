class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        long long n=nums.size();
        long long maxi=0;
        for(long long i=0;i<n;i++){
            maxi=max(maxi,(long long)abs(nums[i]-nums[(i+1)%n]));
        }
        return maxi;
    }
};