class Solution {
public:
    map<int,map<string,int>> dp;
    string vis="0000000000";
    int f(int i, int tight, int n){
        if(i==n) return 1;

        if(dp.count(i) && dp[i].count(vis)) return dp[i][vis];

        int count=0;
        for(int d=0;d<=9;d++){
            if(d==0 && tight) count+=f(i+1,1,n);
            else if(vis[d]=='0'){
                vis[d]='1';
                count+=f(i+1,0,n);
                vis[d]='0';
            }
        }
        return dp[i][vis]=count;

    }
    int countNumbersWithUniqueDigits(int n) {
        return f(0,1,n);
    }
};