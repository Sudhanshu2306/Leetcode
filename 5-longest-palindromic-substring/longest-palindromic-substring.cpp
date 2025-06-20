class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=0;
        string ans="";
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                string x(s.begin()+l,s.begin()+r+1);
                if(maxi<r-l+1){
                    maxi=r-l+1; ans=x;
                }
                l--; r++;
            }
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                string x(s.begin()+l,s.begin()+r+1);
                if(maxi<r-l+1){
                    maxi=r-l+1; ans=x;
                }
                l--; r++;
            }
        }
        return ans;
    }
};