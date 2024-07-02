class Solution {
public:
    int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        if(ind>=nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int len=0+f(ind+1,prev,nums,dp);
        if(nums[ind]%nums[prev]==0 || prev==-1) len=max(len,1+f(ind+1,ind,nums,dp));

        return dp[ind][prev+1]=len;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1), hash(n,0);

        // return f(0,-1,nums,dp);

        int maxi=1;
        int lastInd=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastInd=i;
            }
        }
        vector<int> ans; 
        ans.push_back(nums[lastInd]);
        while(lastInd!=hash[lastInd]){
            lastInd=hash[lastInd];
            ans.push_back(nums[lastInd]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};