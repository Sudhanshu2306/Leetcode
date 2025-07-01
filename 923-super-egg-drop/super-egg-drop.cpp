class Solution {
public:
    int dp[10001][101];
    // dp state is ki dp[n][k] represents we are able to explore nth floor, k eggs being used!
    int f(int k, int n){
        if(n==0 || n==1) return n;
        if(k==1) return n;

        if(dp[n][k]!=-1) return dp[n][k];

        int mini=INT_MAX;
        int s=0,e=n;
        // for determining floor we use BS
        while(s<=e){
            int mid=s+(e-s)/2;
            int down=f(k-1,mid-1);
            int up=f(k,n-mid);

            int curr=1+max(down,up);

            if(down<up) s=mid+1;
            else e=mid-1;
            mini=min(mini,curr);
        }
        return dp[n][k]=mini;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return f(k,n);
    }
};