class Solution {
public:
    int countHomogenous(string s) {
        int count=1;
        int mod=1e9+7;
        int n=s.length();
        int i=0;
        int ans=0;
        while(i<n){
            if(s[i]==s[i+1]){
                count++;
            }
            else{
                ans += (((int64_t)count) * (count + 1)) % mod / 2;
                count=1;
            }
            i++;
        }
        return (ans%mod);
    }
};