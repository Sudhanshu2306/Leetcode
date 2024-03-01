class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0, zero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') one++;
            else zero++;
        }
        string ans="";
        if(one==1){
            for(int i=0;i<zero;i++){
                ans+="0";
            }
            ans+="1";
        }
        else{
            for(int i=0;i<one-1;i++){
                ans+="1";
            }
            for(int i=0;i<zero;i++){
                ans+="0";
            }
            ans+="1";
        }
        return ans;
    }
};