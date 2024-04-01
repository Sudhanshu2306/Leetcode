class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int n=s.size();
        bool flag=true;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ' && !flag) break;
            if(s[i]!=' '){
                len++; flag=false;
            }
        }
        return len;
    }
};