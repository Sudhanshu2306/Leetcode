class Solution {
public:
    int f(vector<int> &nums, int count, int mask, vector<int> &dp){
        int n=nums.size();
        if(count>=n/2) return 0;
        if(dp[mask]!=-1) return dp[mask];
        int maxi=0;
        for(int i=0;i<n;i++){
            if((1&(mask>>i))==1) continue;
            for(int j=i+1;j<n;j++){
                if((1&(mask>>j))==1) continue;

                int newmask=mask|(1<<i)|(1<<j);
                int x=(count+1)*__gcd(nums[i],nums[j]); // 1 based indexing
                int rem=f(nums,count+1,newmask,dp);
                maxi=max(maxi,x+rem);
            }
        }
        return dp[mask]=maxi;
    }
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        int x=1<<n;
        vector<int> dp(x+1,-1);

        int ans=f(nums,0,0,dp);
        return ans;
    }
};