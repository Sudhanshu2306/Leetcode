class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        char ch1,ch2;
        for(int i=0;i<s.size();i++){
            if(s[i]!='9'){
                ch1=s[i];
                break;
            } 
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                ch2=s[i];
                break;
            } 
        }
        string a=s,b=s;
        for(int i=0;i<s.size();i++){
            if(s[i]==ch1) a[i]='9';
            if(s[i]==ch2) b[i]='0';
        }
        int x=stoi(a), y=stoi(b);
        return x-y;
    }
};