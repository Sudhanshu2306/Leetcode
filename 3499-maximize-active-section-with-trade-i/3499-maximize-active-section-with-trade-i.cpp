class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        if(s=="01" || s=="10") return 1;
        s="1"+s+"1";
        int curr=0, prev=0;
        int maxi=0, one=0, zero=0;
        int i=0;
        int n=s.size();
        while(i<n && s[i]=='1') one++, i++;
        while(i<n && s[i]=='0') prev++, i++;

        while(i<n){
            while(i<n && s[i]=='1') one++, i++;
            if(i==n) break;
            while(i<n && s[i]=='0') curr++, i++;
            zero=max(zero,prev+curr);
            prev=curr; curr=0;
        }
        return one+zero-2;
    }
};