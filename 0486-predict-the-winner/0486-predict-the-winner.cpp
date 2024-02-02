class Solution {
public:

    int f(int s, int e,int turn, vector<int> &nums, vector<vector<vector<int>>> &dp){
        if(s>e) return 0;
        if(dp[s][e][turn]!=-1) return dp[s][e][turn];

        if(turn==0)
            return dp[s][e][turn]=max(nums[s]+f(s+1,e,1,nums,dp),nums[e]+f(s,e-1,1,nums,dp));
        else
            return dp[s][e][turn] = min(f(s+1,e,0,nums,dp),f(s,e-1,0,nums,dp));

    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n,vector<int>(2,-1)));
        int s=0; int e=n-1;
        int a= f(s,e,0,nums,dp);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(a>=(sum-a)) return true;
        else return false;
    }
};