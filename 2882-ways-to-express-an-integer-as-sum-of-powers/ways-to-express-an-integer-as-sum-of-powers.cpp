class Solution {
public:
    int mod=1e9+7;
    int dp[301][301];
    int f(int n, int z, int x){
        if(z==0){
            return n==0;
        }
        if(n==0) return 1;
        if(n<0) return 0;

        if(dp[n][z]!=-1) return dp[n][z];
        int take=f(n-pow(z,x),z-1,x)%mod;
        int nottake=f(n,z-1,x)%mod;

        return dp[n][z]=(take+nottake)%mod;
    }
    int numberOfWays(int n, int x) {
        int z=1;
        for(int i=1;i<=n;i++){
            if(pow(i,x)==n){
                z=i; break;
            }
            else if(pow(i,x)>n) break;
            else z=i;
        }
        memset(dp,-1,sizeof(dp));
        return f(n,z,x)%mod;
    }
};