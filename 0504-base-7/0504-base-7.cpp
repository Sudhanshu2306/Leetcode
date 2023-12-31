class Solution {
public:
    string convertToBase7(int num) {
        int a=abs(num);
        string ans="";
        if(num==0){
            return "0";
        }
        while(a>0){
            ans+=to_string(a%7);
            a/=7;
        }
        if(num<0){
            ans+="-";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};