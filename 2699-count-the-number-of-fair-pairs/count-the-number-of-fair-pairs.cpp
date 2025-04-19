class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=0;
       
        for(int i=0;i<n;i++){
            long long x=lower-nums[i]; long long y=upper-nums[i];
            long long count=upper_bound(nums.begin()+i+1,nums.end(),y)-lower_bound(nums.begin()+i+1,nums.end(),x);
            ans+=count;
        }   
        return ans;    
    }
};