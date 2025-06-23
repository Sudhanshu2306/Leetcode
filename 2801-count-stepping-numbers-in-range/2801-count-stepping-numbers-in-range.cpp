class Solution {
public:
    int mod=1e9+7;
    int dp[101][2][10][2];
    int f(int i, int tight, int prev, int zero, string &s){
        if(i==s.size()){
            if(zero) return 1;
            return 0;
        }

        if(dp[i][tight][prev][zero]!=-1) return dp[i][tight][prev][zero];

        int count=0;
        int limit=(tight==1)?s[i]-'0':9;

        for(int d=0;d<=limit;d++){
            int new_tight=tight & (limit==d);
            if(zero==0 && d==0) count=(count+f(i+1,new_tight,prev,0,s))%mod;
            else if((zero==0 && d>0) || (abs(d-prev)==1)) count=(count+f(i+1,new_tight,d,1,s))%mod;
        }

        return dp[i][tight][prev][zero]=count;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        int a=f(0,1,0,0,high);
        memset(dp,-1,sizeof(dp));
        int b=f(0,1,0,0,low);

        bool flag=true;
        for(int i=1;i<low.size();i++){
            if(abs(low[i]-low[i-1])!=1){
                flag=false; break;
            }
        }
        if(flag) b--;
        return (a-b+mod)%mod;
    }
};