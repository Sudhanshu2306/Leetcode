class Solution {
public:
    bool hasSameDigits(string s) {
        string ans="";
        while(s.size()>2){
            for(int i=0;i<s.size()-1;i++){
                ans+=to_string(((s[i]-'0')+(s[i+1]-'0'))%10);
            }
            s=ans;
            ans="";
        }
        if(s[0]==s[1]) return true;
        else return false;
    }
};