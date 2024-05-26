class Solution {
public:
int mod=1e9+7;
    int f(int ind, int a, int l, vector<vector<vector<int>>> &dp){
        if(a>1 || l>2) return 0;
        if(ind==0) return 1;

        if(dp[ind][a][l]!=-1) return dp[ind][a][l];

        int abs=f(ind-1,a+1,0,dp);
        int late=f(ind-1,a,l+1,dp);
        int present=f(ind-1,a,0,dp);

        return dp[ind][a][l]=((abs+late)%mod+present)%mod;

    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(4,-1)));
        // return f(n,0,0,dp);

        // base case
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                dp[0][i][j]=1;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                dp[i][2][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][3]=0;
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<3;k++){
                    long long ans=dp[i-1][j+1][0]%mod;
                    ans+=dp[i-1][j][0]%mod;
                    ans+=dp[i-1][j][k+1]%mod;

                    dp[i][j][k]=ans%mod;
                }
            }
        }
        return dp[n][0][0]%mod;
    }
};