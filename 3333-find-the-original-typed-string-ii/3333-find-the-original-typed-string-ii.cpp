class Solution {
public:
    int mod=1e9+7;
    int possibleStringCount(string word, int k) {
        int n=word.size();
        vector<int> a;
        int count=1; int total=1;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                count++;
            }
            else{
                total=((long long)total*count)%mod;
                a.push_back(count-1);
                count=1;
            }
        }
        
        total=((long long)total*count)%mod;
        a.push_back(count-1);

        if(a.size()>=k) return total;

        k-=a.size();
        vector<int> dp(n+1,0);
        dp[0]=1;

        for(auto it:a){
            vector<int> pre(k); pre[0]=dp[0];
            for(int i=1;i<k;i++) pre[i]=(pre[i-1]+dp[i])%mod;
            for(int i=0;i<k;i++){
                if(i-it-1>=0) dp[i]=(pre[i]-pre[i-it-1]+mod)%mod;
                else dp[i]=pre[i];
            }
        }
        int x=0;
        for(auto it:dp) x=(x+it)%mod;

        return (total-x+mod)%mod;
    }
};