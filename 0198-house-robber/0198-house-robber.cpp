class Solution {
public:
    // memoisation ( top-down approach )     
    int solve(int index, vector<int> &nums, vector<int> &dp){
        if(index==0){
            return nums[index];
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        
        int pick=solve(index-2,nums,dp)+nums[index];
        int notpick=solve(index-1,nums,dp) + 0;
        
        return dp[index]=max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        // return solve(n-1,nums,dp);
        dp[0]=nums[0];
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick;
            // note to self: a tricky part is for index getting a negative value, just pick the current index element value, we cannot add dp[of some negative number]!             
            if(i>1)
                pick=prev2+nums[i];
            else{
                pick=nums[i];
            }
            int notpick=prev+0;
            int temp=max(pick,notpick);
            prev2=prev;
            prev = temp;
        }
        return prev;
    }
};