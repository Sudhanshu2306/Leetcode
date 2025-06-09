class Solution {
public:
    long long mod=1e9+7;
    long long bi_exp(long long a, long long b){
        long long ans=1;
        while(b>0){
            if(b&1){
                ans=(ans*a)%mod;
            }
            a=(a*a)%mod;
            b/=2;
        }
        return ans;
    }
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        int s=ranges[0][0], e=ranges[0][1];

        int n=ranges.size();
        long long count=1;
        for(int i=1;i<n;i++){
            if(e>=ranges[i][0]){
                e=max(e,ranges[i][1]);
            }
            else{
                count++;
                s=ranges[i][0], e=ranges[i][1];
            }
        }
        return bi_exp(2LL,count);
    }
};