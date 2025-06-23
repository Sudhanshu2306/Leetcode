class Solution {
public:
    int dp[10][2][2];
    int f(int i, int tight, int valid, vector<string> &a, string &s){
        if(i==s.size()){
            return valid;
        }

        if(dp[i][tight][valid]!=-1) return dp[i][tight][valid];
        int count=0;

        int limit=tight?s[i]-'0':9;

        if(!valid) count+=f(i+1,0,0,a,s);
        for(auto it:a){
            int d=it[0]-'0';
            int new_tight=tight && (limit==d);
            if(d>limit) break;  
            count+=f(i+1,new_tight,1,a,s);
        }
        return dp[i][tight][valid]=count;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        int ans=f(0,1,0,digits,s);
        return ans;
    }
};