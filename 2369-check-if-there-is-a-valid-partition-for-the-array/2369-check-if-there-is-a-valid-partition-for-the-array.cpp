class Solution {
public:
    int f(int i, vector<int> &nums, vector<int> &dp){
        if(i>=nums.size()) return 1;
        if(dp[i]!=-1) return dp[i];

        int a=0,b=0,c=0;
        if(i+1<nums.size() && nums[i]==nums[i+1]){
            a=f(i+2,nums,dp);
            if(i+2<nums.size() && nums[i]==nums[i+2]){
                b=f(i+3,nums,dp);
            }
        } 
        if(i+2<nums.size() && nums[i+1]==nums[i]+1 && nums[i+2]==nums[i+1]+1){
            c=f(i+3,nums,dp);
        }
        return dp[i]=a|b|c;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return f(0,nums,dp);
    }
};