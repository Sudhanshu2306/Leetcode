class Solution {
public:
    bool isVowel(char c){
        string vowel="aeiouAEIOU";
        for(int i=0;i<10;i++){
            if(c==vowel[i]){
                return true;
            }
        }
        return false;
    }
    string reverseVowels(string s) {
        int n=s.length();
        string v="";
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                v.push_back(s[i]);
            }
        }
        reverse(v.begin(),v.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                s[i]=v[j++];
            }
        }
        return s;
    }
};