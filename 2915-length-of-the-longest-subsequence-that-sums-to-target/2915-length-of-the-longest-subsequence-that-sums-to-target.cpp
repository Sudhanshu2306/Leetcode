class Solution {
public:
    int f(vector<int> &nums, int ind, int target, vector<vector<int>> &dp){
        if(target==0) return 0;
        if(ind<0) return -90000000;

        if(dp[ind][target]!=-1) return dp[ind][target];
        int pick=INT_MIN;
        if(nums[ind]<=target) pick=1+f(nums,ind-1,target-nums[ind],dp);
        int not_pick=0+f(nums,ind-1, target,dp);

        return dp[ind][target]=max(pick,not_pick);

    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans=f(nums,n-1,target,dp);
        return ans<=0?-1:ans;
    }
};