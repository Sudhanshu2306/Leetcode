class Solution {
public:
    int dp[32][2][2];
    int f(int i, int tight, int prev, string &s){
        if(i==s.size()) return 1;

        if(dp[i][tight][prev]!=-1) return dp[i][tight][prev];

        int count=0;
        int limit=tight?s[i]-'0':1;

        for(int d=0;d<=limit;d++){
            int nt=tight && (limit==d);
            if((d&prev)==0) count+=f(i+1,nt,d,s);
        }
        return dp[i][tight][prev]=count;
    }
    int findIntegers(int n) {
        string s="";
        memset(dp,-1,sizeof(dp));
        while(n){
            int x=n%2;
            s+=to_string(x); n/=2;
        }
        reverse(s.begin(),s.end());
        return f(0,1,0,s);
    }
};