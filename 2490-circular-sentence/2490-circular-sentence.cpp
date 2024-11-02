class Solution {
public:
    bool isCircularSentence(string s) {
        int n=s.size();
        char last;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(s[i]!=' ') last=s[i];
            else{
                if(s[i+1]!=last) flag=false;
            }
        }
        if(flag && s[n-1]==s[0]) return true;
        return false;
    }
};