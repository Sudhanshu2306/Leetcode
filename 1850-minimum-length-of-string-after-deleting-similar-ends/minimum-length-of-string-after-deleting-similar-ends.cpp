class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int i=0; int j=n-1;

        while(i<j && s[i]==s[j]){
            while(s[i]==s[i+1] && i+1<j) i++;
            while(s[j]==s[j-1] && i+1<j) j--;

            i++; j--;
        }

        return (j-i+1);
    }
};