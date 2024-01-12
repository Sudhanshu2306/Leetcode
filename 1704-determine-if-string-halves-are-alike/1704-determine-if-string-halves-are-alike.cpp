class Solution {
public:
    bool halvesAreAlike(string s) {
        int vowelCount=0;
        int n=s.length();
        for(auto c: s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
              c=='A' || c=='E' || c=='I' || c=='O' || c=='U' ) vowelCount++;
        }
        if(vowelCount%2!=0 || n%2!=0) return false;
        int x=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || 
              s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' ) x++;
            
            if(x==(vowelCount/2) && i==(n/2 -1)) return true;
        }
        return false;
    }
};