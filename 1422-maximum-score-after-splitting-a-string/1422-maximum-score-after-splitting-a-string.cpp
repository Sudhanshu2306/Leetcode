class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int n1=0,n0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                n1++;
            }
        }
        int maxi=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                n1--;
            }
            else{
                n0++;
            }
            maxi=max(maxi,n1+n0);
        }
        return maxi;
    }
};