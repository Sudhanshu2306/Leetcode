class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        string ans="";
        int n=s.size();
        vector<long long> pre(n); pre[n-1]=(long long)shifts[n-1]%26;
        for(int i=n-2;i>=0;i--) pre[i]=(pre[i+1]+(long long)shifts[i])%26;
        
        for(int i=0;i<n;i++){
            int x=s[i]-'a';
            x+=pre[i];
            x%=26;
            char y='a'+x;
            ans+=y;
        }
        return ans;
    }
};