class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int notK=-1;
        int maxi=-1, mini=-1;
        long long count=0;

        for(int i=0;i<n;i++){
            if(nums[i]>maxK || nums[i]<minK) notK=i;
            if(nums[i]==maxK) maxi=i;
            if(nums[i]==minK) mini=i;

            count+=(max(min(maxi,mini)-notK,0));
        }
        return count;
    }
};