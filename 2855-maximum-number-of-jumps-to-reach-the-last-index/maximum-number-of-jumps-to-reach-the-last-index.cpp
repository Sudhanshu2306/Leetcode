class Solution {
public:
int f(int i,vector<int> &nums,int tar, vector<int> &dp){
    int n=nums.size();
    if(i==n-1) return 0;
    if(i>=n) return -1e9;
    
    if(dp[i]!=-1) return dp[i];
    int ans=-1e9;
    for(int j=i+1;j<n;j++){
        // -target<=nums[j]-nums[i]<=target
        if(abs(nums[j]-nums[i])<=tar) ans=max(ans,1+f(j,nums,tar,dp));
    }
    return dp[i]= ans;
}
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(1000+5,-1);
        int ans=f(0,nums,target,dp);
        if(ans<=-1e8) return -1;
        else return ans;
    }
};