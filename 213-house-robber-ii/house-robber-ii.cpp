class Solution {
public:
    int rob(vector<int>& nums) {
    // first and last cannot be together, so lets consider two subsets of array, one not having 1st element and the other not having last element.
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n);
        // excluding 1st element
        dp[0]=0;
        for(int i=1;i<n;i++){
            int pick;
            if(i-2<0)
                pick=nums[i];
            else
                pick=nums[i]+dp[i-2];
            
            int notpick=dp[i-1]+0;
            
            dp[i]=max(pick,notpick);
        }
        int ans1=dp[n-1];
        
        //excluding last element
        dp.clear();
        dp[0]=nums[0];
        for(int i=1;i<n-1;i++){
            int pick;
            if(i-2<0)
                pick=nums[i];
            else
                pick=nums[i]+dp[i-2];
            
            int notpick=dp[i-1]+0;
            
            dp[i]=max(pick,notpick);
        }
        int ans2=dp[n-2];
        return max(ans1,ans2);
    }
};

// still space can be optimised using 2 variables, rather than using a vector!