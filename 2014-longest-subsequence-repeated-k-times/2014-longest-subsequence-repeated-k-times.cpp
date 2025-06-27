class Solution {
public:
    bool ff(string &s, string ans, int k){
        int j=0,m=ans.size();
        for(int i=0;i<s.size();i++){
            if(s[i]==ans[j]) j++;
            if(j==m){
                k--;
                j=0;
            } 
            if(k==0) return true;
        }
        return k<=0;
    }
    string f(string &s, string ans, int k){
        int maxLen=0;
        string x=ans;

        for(char i='z';i>='a';i--){
            ans+=i;
            if(ff(s,ans,k)){
                string temp=f(s,ans,k);
                if(temp.size()>maxLen){
                    maxLen=temp.size();
                    x=temp;
                }
            }
            ans.pop_back();
        }
        return x;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans="";
        return f(s,ans,k);
    }
};