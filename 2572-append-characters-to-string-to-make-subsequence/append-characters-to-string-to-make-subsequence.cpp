class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.length();
        int i=0;int j=0;
        // int count=0;
        while(i<n){
            if(s[i]==t[j]){
                j++;
                // count++;
            }
            i++;
            if(j==t.length()) return 0;
        }
        return t.length()-j;
    }
};