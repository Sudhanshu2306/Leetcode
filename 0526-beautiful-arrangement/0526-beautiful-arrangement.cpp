class Solution {
public:
    int dp[16][1<<15];
    int f(int i, int mask, int n){
        if(i==n) return 1;
        if(dp[i][mask]!=-1) return dp[i][mask];

        int count=0;
        for(int j=0;j<n;j++){
            if(((1<<j)&mask)==0){
                if((i+1)%(j+1)==0 || (j+1)%(i+1)==0){
                    count+=f(i+1,(mask|(1<<j)),n);
                }
            }
        }
        return dp[i][mask]=count;
    }
    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,n);
    }
};