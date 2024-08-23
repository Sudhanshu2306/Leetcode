class Solution {
public:
    string fractionAddition(string s) {
        int num=0,den=1;
        int n=s.size();
        int i=0;
        while(i<n){
            int f=1;
            if(s[i]=='+' || s[i]=='-'){
                i++;
                if(s[i-1]=='-') f=0;
            }
            int x=0;
            while(i<n && isdigit(s[i])){
                x=x*10+(s[i]-'0');
                i++;
            }
            if(f==0) x=0-(x);
            i++;
            int y=0;
            while(i<n && isdigit(s[i])){
                y=y*10+(s[i]-'0');
                i++;
            }
            num=num*y+den*x;
            den=den*y;

            int gcd=__gcd(abs(num),abs(den));
            num/=gcd; den/=gcd;
        }
        string ans="";
        ans+=(to_string(num)+"/"+to_string(den));
        return ans;
    }
};