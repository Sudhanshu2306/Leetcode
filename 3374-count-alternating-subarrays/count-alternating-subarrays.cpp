class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<long long> dp(n,1);
        // return f(nums,0,dp);
        long long ans=0;
        for(int i=0;i<n;i++){
            if(i!=0){
                if(nums[i]!=nums[i-1]) dp[i]=dp[i-1]+1;
            }
            ans+=dp[i];
        }
        return ans;
    }
};