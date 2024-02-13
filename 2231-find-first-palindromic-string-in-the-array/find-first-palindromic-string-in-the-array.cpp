class Solution {
public:

    bool isPalindrome(string s){
        string x=s;
        reverse(x.begin(),x.end());
        return x==s;
    }
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            if(isPalindrome(words[i])) return words[i];
        }
        return "";
    }
    
};