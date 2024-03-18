class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.length();
        int common=1;
        
        for(int i=k;i<n;i+=k){
            int len=n-i;
            if(word.substr(0,len)==word.substr(i,len)) break;

            common++;
        }
        return common;
    }
};