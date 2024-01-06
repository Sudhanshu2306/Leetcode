class Solution {
public:
    int titleToNumber(string s) {
        int size=s.length();
        long long num=0;
        for(int i=0;i<size;i++){
            num=num*26+int(s[i]-'A'+1);
        }
        return num;
    }
};