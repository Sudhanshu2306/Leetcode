class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.length());
        unsigned long long x=0;
        for(int i=0;i<word.length();i++){
            x=x*10+(word[i]-'0');
            if(x%m==0) ans[i]=1;
            else ans[i]=0;

            x=x%m;
        }
        return ans;
    }
};