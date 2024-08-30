class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.size();
        int i=0, j=n-1;
        string ans="";
        while(i<=j){
            if(s[i]==s[j]){
                ans+=s[i];
                i++;j--;
            }
            else{
                ans+=min(s[i],s[j]);
                i++; j--;
            }
        }
        string x="";
        for(int i=0;i<(n/2);i++){
            x+=ans[i];
        }
        reverse(x.begin(),x.end());
        return ans+x;
    }
};