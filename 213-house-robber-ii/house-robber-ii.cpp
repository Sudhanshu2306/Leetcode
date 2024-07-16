class Solution {
public:
    // space can be optimised using 2 variables, rather than using a vector!
    // something like this:
    
    int rob(vector<int>& nums) {
    // first and last cannot be together, so lets consider two subsets of array, one not having 1st element and the other not having last element.
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n);
        // excluding 1st element
        int pa1=0;
        int pa2=0;
        for(int i=1;i<n;i++){
            int pick;
            if(i-2<0)
                pick=nums[i];
            else
                pick=nums[i]+pa2;
            
            int notpick=pa1+0;
            
            pa2=pa1;
            pa1=max(pick,notpick);
        }
        int ans1=pa1;
        
        //excluding last element
        int pb1=nums[0];
        int pb2=0;
        for(int i=1;i<n-1;i++){
            int pick;
            if(i-2<0)
                pick=nums[i];
            else
                pick=nums[i]+pb2;
            
            int notpick=pb1+0;
            
            pb2=pb1;
            pb1=max(pick,notpick);
        }
        int ans2=pb1;
        return max(ans1,ans2);
    }
};

/* 
       tabulated solution 
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
        return max(an1,ans2);
        
*/

        