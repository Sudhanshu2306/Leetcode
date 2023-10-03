class Solution {
public:
    int numSub(string s) {
        long long mod=1e9+7;
        long long count1=0;
        long long ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count1++;
            }
            else{
                long long x=((count1*(count1+1))/2)%mod;
                ans+=x;
                count1=0;
            }
        }
        ans+=(((count1*(count1+1))/2)%mod);
        return ans%mod;
    }
};