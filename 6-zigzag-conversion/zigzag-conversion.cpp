class Solution {
public:
    string convert(string s, int k) {
        int n=s.size();
        if(k==1 || k>=n) return s;
        string ans="";
        int x=2*(k-1);
        for(int i=0;i<k;i++){
            for(int j=0;j+i<n;j+=x){
                ans+=s[i+j];
                if(i!=0 && i!=k-1 && j-i+x<n) ans+=s[j-i+x];
            }
        }
        return ans;
    }
};