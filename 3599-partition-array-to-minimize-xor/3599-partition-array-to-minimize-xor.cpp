class Solution {
public:
    int dp[251][251];
    int f(int i, int k, vector<int> &nums){
        if(i>=nums.size()) return 1e9;

        if(k==0){
            int ans=0;
            for(int d=i;d<nums.size();d++){
                ans^=nums[d];
            }
            return dp[i][k]=ans;
        }
        if(dp[i][k]!=-1) return dp[i][k];

        int mini=1e9;
        int exor=0;
        for(int d=i;d<nums.size();d++){
            exor^=nums[d];
            int curr=f(d+1,k-1,nums);
            int ans=max(exor,curr);
            mini=min(mini,ans);
        }
        return dp[i][k]=mini;
    }
    int minXor(vector<int>& nums, int k) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        // k subarrays means k-1 partitions
        return f(0,k-1,nums);
    }
};