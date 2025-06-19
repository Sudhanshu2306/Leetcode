class Solution {
public:
    long long dp[16][2];
    long long f(int i, int tight, string &s, int k, string &end){
        if(i==s.size()) return 1;

        if(dp[i][tight]!=-1) return dp[i][tight];

        long long count=0;
        int limit=tight?s[i]-'0':9;
        limit=min(limit,k);

        int start=s.size()-end.size();
        if(i>=start){
            if(tight==0) return dp[i][tight]=1;
            if(s[i]>end[i-start]) return dp[i][tight]=1;
            if(s[i]<end[i-start]) return dp[i][tight]=0;
            if(s[i]==end[i-start]) return dp[i][tight]=f(i+1,1,s,k,end);
        }

        for(int d=0;d<=limit;d++){
            int new_tight=tight && ((s[i]-'0')==d);
            count+=f(i+1,new_tight,s,k,end);
        }
        return dp[i][tight]=count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        memset(dp,-1,sizeof(dp));
        string a=to_string(start-1);
        long long x=0;
        if(a.size()>=s.size()){
            x=f(0,1,a,limit,s);
        }
        memset(dp,-1,sizeof(dp));
        string b=to_string(finish);
        long long y=f(0,1,b,limit,s);

        return abs(y-x);
    }
};