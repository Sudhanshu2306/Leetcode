class Solution {
public:
int maxi, mini;
long long dp[24][401][2];
int mod=1e9+7;
    long long f(int i, int sum, int tight, string &s){
        if(i==s.size()){
            if(sum>=mini && sum<=maxi) return 1;
            return 0;
        }
        if(dp[i][sum][tight]!=-1) return dp[i][sum][tight];

        long long count=0;
        int limit=tight?s[i]-'0':9;
        for(int j=0;j<=limit;j++){
            int nt=tight && (j==limit);
            count=(count+f(i+1,sum+j,nt,s))%mod;
        }
        return dp[i][sum][tight]=count;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        maxi=max_sum; mini=min_sum;
        memset(dp,-1,sizeof(dp));

        int x=f(0,0,1,num2);
        memset(dp,-1,sizeof(dp));
        int y=f(0,0,1,num1);
        int sum=0;
        for(int i=0;i<num1.size();i++){
            sum+=num1[i]-'0';
        }
        if(sum>=mini && sum<=maxi) y--;
        return (x-y+mod)%mod;
    }
};