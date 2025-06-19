class Solution {
public:
    int dp[10][2][10];
    int f(int i, int tight, int one, string &s){
        if(i==s.size()) return one;

        if(dp[i][tight][one]!=-1) return dp[i][tight][one];

        int count=0;
        int limit=tight?s[i]-'0':9;
        for(int d=0;d<=limit;d++){
            int new_tight=tight && (d==limit);
            count+=f(i+1,new_tight,one+(d==1),s);
        }
        return dp[i][tight][one]=count;
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return f(0,1,0,s);
    }
};