class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // we just need to calculate the length of the string after t transformation, not the string!
        vector<long long> cnt(26,0);
        int mod=1e9+7;
        for(auto it:s) cnt[it-'a']++;

        for(int i=0;i<t;i++){
            vector<long long> temp(26,0);
            for(int j=0;j<26;j++){
                if(j==25){
                    temp[0]=(temp[0]+cnt[j])%mod;
                    temp[1]=(temp[1]+cnt[j])%mod;
                }
                else{
                    temp[j+1]=(cnt[j]+temp[j+1])%mod;
                }
            }
            cnt=temp;
        }
        long long ans=0;
        for(auto it:cnt) ans=(ans+it)%mod;
        return ans;
    }
};