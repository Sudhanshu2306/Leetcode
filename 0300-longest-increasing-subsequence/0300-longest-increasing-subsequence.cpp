class Solution {
public:
    int recursion_memo(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        // base case
        if(ind>=nums.size()) return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int pick=INT_MIN;
        if(prev==-1 || nums[ind]>nums[prev]) pick = 1 + recursion_memo(ind+1,ind,nums,dp);
        int notpick = recursion_memo(ind+1,prev,nums,dp) + 0;

        return dp[ind][prev+1] = max(pick, notpick);
    }
    /*
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return recursion_memo(0,-1,nums,dp);
    } */

    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> temp; temp.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>temp.back()) temp.push_back(arr[i]);
            else {
                int ind = lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                temp[ind]=arr[i];
            }
        }
        return temp.size();
    }

};