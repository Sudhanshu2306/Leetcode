class Solution {
public:
    string ff(int n){
        if(n==1) return "0";
        string ans;
        string x=ff(n-1);
        string y=x; reverse(y.begin(),y.end());
        for(int i=0;i<x.size();i++){
            if(y[i]=='0') y[i]='1';
            else y[i]='0';
        }
        ans=x+"1"+y;
        return ans;
    }
    char findKthBit(int n, int k) {
        string ans=ff(n);
        return ans[k-1];
    }
};