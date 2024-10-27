class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> count(26,0);
        for(auto it:s) count[it-'a']++;
        long long mod=1e9+7;
        for(long long i=0;i<t;i++){
            vector<long long> nc(26,0);
            for(long long j=0;j<26;j++){
                if(j==25){
                    nc[0]=(nc[0]+count[25])%mod;
                    nc[1]=(nc[1]+count[25])%mod;
                }
                else{
                    nc[j+1]=(nc[j+1]+count[j])%mod;
                }
            }
            count=nc;
        }
        long long ans=0;
        for(long long i=0;i<26;i++) ans=(ans+count[i])%mod;
        return ans;
    }
};