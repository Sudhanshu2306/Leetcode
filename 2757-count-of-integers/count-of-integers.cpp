class Solution {
public:
    int mod=1e9+7;
    long long dp[23][401][2];
    long long f(int i, int mini, int maxi, int tight, long long sum, string &s){
        if(i==s.size()){
            if(sum>=mini && sum<=maxi) return 1;
            return 0;
        }

        if(dp[i][sum][tight]!=-1) return dp[i][sum][tight];
        long long count=0;

        int limit=(tight==1?s[i]-'0':9);
        for(int k=0;k<=limit;k++){
            int new_tight=tight & (k==limit);
            count=(count+f(i+1,mini,maxi,new_tight,sum+k,s))%mod;
        }
        return dp[i][sum][tight]=count%mod;

    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n=num2.size();
        memset(dp,-1,sizeof(dp));
        int a=f(0,min_sum,max_sum,1,0,num2);
        memset(dp,-1,sizeof(dp));
        int b=f(0,min_sum,max_sum,1,0,num1);

        int sum=0;
        for(auto it:num1) sum+=(it-'0');

        if(sum>=min_sum && sum<=max_sum) b--;
        return (a-b+mod)%mod;
    }
};