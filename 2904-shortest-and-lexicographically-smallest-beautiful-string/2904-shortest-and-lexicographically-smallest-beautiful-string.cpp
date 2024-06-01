class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        string ans="";
        int count=0; int mini=INT_MAX;

        while(j<n){
            if(s[j]=='1')count++;
            while(count>k || s[i]=='0'){
                if(s[i]=='1') count--;
                i++;
            }

            if(count==k){
                int x=j-i+1;
                string temp=s.substr(i,x);
                if(x<mini){
                    mini=x;
                    ans=temp;
                }
                else if(x==mini && temp<ans) ans=temp;
            }
            j++;
        }
        return ans;
    }
};