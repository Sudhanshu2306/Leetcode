class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans="";
        int n=word.length();
        int ind=0;
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                ind=i;
                break;
            }
        }
        for(int i=ind;i>=0;i--){
            ans+=word[i];
        }
        for(int i=ind+1;i<n;i++) ans+=word[i];
        return ans;
    }
};