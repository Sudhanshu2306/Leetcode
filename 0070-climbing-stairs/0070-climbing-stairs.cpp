class Solution {
public:
    
    int solve(int ind, vector<int> &dp){
        if(ind==1 || ind==0) return 1;

        if(dp[ind]!=-1) return dp[ind];
        int x=solve(ind-1,dp);
        int y=solve(ind-2,dp);

        return dp[ind]=x+y;
    }
    
    int climbStairs(int n) {
        // base case
        // vector<int> dp(n+1,-1);
        // return solve(n,dp);

        if(n==0 || n==1){
            return 1;
        }
        int prev=1; int curr=1;
        
        for(int i=2;i<=n;i++){
            //tabulation
            int temp=curr;
            curr=prev+curr;
            prev=temp;
        }
        return curr;
    }
};
