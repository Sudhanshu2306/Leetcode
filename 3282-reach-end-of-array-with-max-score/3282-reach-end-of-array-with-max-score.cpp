class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        long long i=0;

        while(i<n-1){
            long long j=i+1;
            while(j<n && nums[j]<=nums[i]) j++;
            if(j>=n) j=n-1;

            ans+=(j-i)*(long long)nums[i];
            i=j;
        }
        return ans;
    }
};