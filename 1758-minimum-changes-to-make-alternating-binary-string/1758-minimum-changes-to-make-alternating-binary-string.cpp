class Solution {
public:
    int minOperations(string s) {
        int a=0,b=0;
        for(int i=0;i<s.length();i++){
            if((i%2==0) && s[i]=='0'){
                a++;
            }
            else if((i%2==1) && s[i]=='1'){
                a++;
            }
            else if((i%2==0) && s[i]=='1'){
                b++;
            }
            else if((i%2==1) && s[i]=='0'){
                b++;
            }
        }
        return a>b? b:a;
    }
};