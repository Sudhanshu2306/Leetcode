class Solution {
public:

    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int coins=nums[i-1]*nums[ind]*nums[j+1]+ f(i,ind-1,nums,dp)+ f(ind+1,j,nums,dp);
            maxi=max(maxi,coins);
        }
        return dp[i][j]=maxi;
    }

    int tabulation(vector<int>&nums){
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        /* one more important point i is from 1 to n, j is from 1 to n, and now ind is from i to j 
        (both inclusive) so this should be reflected in dp vector also, it should be (n+2)x(n+2). */
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                // base case here i.e. when i>j :
                if(i>j) continue;
                int maxi=INT_MIN;
                for(int ind=i;ind<=j;ind++){
                    int coins=nums[i-1]*nums[ind]*nums[j+1]+ dp[i][ind-1]+ dp[ind+1][j];
                    maxi=max(maxi,coins);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        // int n=nums.size();
        // nums.insert(nums.begin(),1);
        // nums.push_back(1);
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return f(1,n,nums,dp);
        return tabulation(nums);
    }
};