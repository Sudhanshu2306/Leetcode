class Solution {
public:
    int dp[12][6][6][2][2][20];
    // {index,odd,even,tight,leading zero,remainder};

    int f(int i, int odd, int even, int tight, int zero, int rem, string &s, int k){
        if(i==s.size()){
            if(rem==0 && odd==even) return 1;
            return 0;
        }

        if(odd>5 || even>5) return 0;

        if(dp[i][odd][even][tight][zero][rem]!=-1) return dp[i][odd][even][tight][zero][rem];

        int count=0;
        int limit=tight?s[i]-'0':9;

        for(int d=0;d<=limit;d++){
            int nt=tight && (d==limit);
            if(zero==0 && d==0) count+=f(i+1,odd,even,nt,0,rem,s,k);
            else if(d%2==0) count+=f(i+1,odd,even+1,nt,1,(rem*10+d)%k,s,k);
            else count+=f(i+1,odd+1,even,nt,1,(rem*10+d)%k,s,k);
        }
        return dp[i][odd][even][tight][zero][rem]=count;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s=to_string(high);
        memset(dp,-1,sizeof(dp));
        int x=f(0,0,0,1,0,0,s,k);
        string t=to_string(low-1);
        memset(dp,-1,sizeof(dp));
        int y=f(0,0,0,1,0,0,t,k);

        return abs(x-y);
    }
};