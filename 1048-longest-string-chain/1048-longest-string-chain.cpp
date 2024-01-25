class Solution {
public:
    bool static comp(string &s, string &t){
        return s.length() < t.length();
    }
    bool f(string &s, string &t){
        int n=s.length(); int m=t.length();
        if(n!=(m+1)) return false;

        int i=0,j=0;
        while(i<n){
            if(s[i]==t[j]){
                i++;j++;
            }
            else i++;
        }
        if(i==n && j==m) return true;
        else return false;
    }

    int longestStrChain(vector<string>& words) {
        // similar to longest increasing subsequence, only difference we neeed to check for consecutive strings for insertion of a character
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxi=1;

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(f(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};