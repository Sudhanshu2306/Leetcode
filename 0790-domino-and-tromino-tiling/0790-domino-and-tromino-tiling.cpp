class Solution {
public:
    int mod=1e9+7;
    int numTilings(int n) {
        if(n==1) return 1;
        vector<long long> di(n+1,0),tri(n+1,0);
        di[1]=1, tri[1]=1;
        di[2]=2, tri[2]=2;

        for(int i=3;i<=n;i++){
            // visualizing n=3
            di[i]=(di[i-1]+di[i-2]+2*tri[i-2])%mod;
            tri[i]=(tri[i-1]+di[i-1])%mod;
        }
        return di[n];
    }
};