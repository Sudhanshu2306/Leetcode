class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxi=0;
        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 && maxi==0 && nums[i]<=threshold) maxi=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]%2==0 && nums[j]%2!=nums[j-1]%2 && nums[j]<=threshold && nums[j-1]<=threshold) maxi=max(maxi,j-i+1);
                else break;
            }
        }
        return maxi;
    }
};