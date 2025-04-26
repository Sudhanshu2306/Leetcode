class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long count=0;

        // okay if I get a maximum greater than maxK or a minimum less than minK, we cannot continue with same subarray
        int maxi=-1,mini=-1;
        int start=-1;

        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK) start=i;
            if(nums[i]==maxK) maxi=i;
            if(nums[i]==minK) mini=i;

            if(maxi!=-1 && mini!=-1) count+=max(min(maxi,mini)-start,0);
        }

        return count;
    }
};