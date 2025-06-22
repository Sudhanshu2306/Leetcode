class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int maxi=1;
        int n=s.size();
        int i=0, j=1, prev=0;
        while(j<n){
            if(s[j]==s[j-1]){
                if(prev) i=prev;
                prev=j;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};