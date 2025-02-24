class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        for(int j=0;j<n;j++){
            if(s[i]==s[j]) continue;
            if(j-i==k) return true;
            i=j;
        }
        if(n-i==k) return true;
        else return false;
    }
};