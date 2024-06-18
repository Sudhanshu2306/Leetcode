class Solution {
public:
    int f(int ind, vector<int> &nums, vector<int> &dp){
        if(ind>=nums.size()) return 1e9;

        if(dp[ind]!=-1) return dp[ind];
        int ans=1e9;
        for(int i=1;i<=nums[ind];i++){
            if(ind+i>=nums.size()) break;
            ans=min(ans,1+f(ind+i,nums,dp));
        }
        return dp[ind]=ans;
    }

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[n-1]=0;
        return f(0,nums,dp);
    }
};