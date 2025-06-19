class Solution {
public:
    int dp[11][2][6][6][20][2];
    // {index,tight,odd,even,remainder,isLeadingZero}

    int f(int i, int tight, int even, int odd, int rem, int zero, int k, string &s){
        if(i==s.size()){
            if(even==odd && rem==0) return 1;
            return 0;
        }
        if(odd>5 || even>5) return 0;
        if(dp[i][tight][odd][even][rem][zero]!=-1) return dp[i][tight][odd][even][rem][zero];
        int count=0;
        int limit=tight==1?s[i]-'0':9;
        for(int d=0;d<=limit;d++){
            int new_tight=tight & (limit==d);
            if(zero==0 && d==0) count+=f(i+1,new_tight,even,odd,rem,0,k,s);
            else if(d%2==0) count+=f(i+1,new_tight,even+1,odd,(rem*10+d)%k,1,k,s);
            else count+=f(i+1,new_tight,even,odd+1,(rem*10+d)%k,1,k,s);
        }
        return dp[i][tight][odd][even][rem][zero]=count;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string a=to_string(low-1);
        string b=to_string(high);
        memset(dp,-1,sizeof(dp));
        int x=f(0,1,0,0,0,0,k,a);
        memset(dp,-1,sizeof(dp));
        int y=f(0,1,0,0,0,0,k,b);

        return y-x;
    }
};