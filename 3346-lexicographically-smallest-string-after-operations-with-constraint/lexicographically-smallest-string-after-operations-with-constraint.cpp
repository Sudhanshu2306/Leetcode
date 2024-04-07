class Solution {
public:
    string getSmallestString(string s, int k) {
        int n=s.size();

        for(int i=0;i<n;i++){
            char ch=s[i];
            int x=s[i]-'a';
            int y=min(x,26-x);
            if(y<=k){
                s[i]='a';
                k-=y;
            }
            else{
                s[i]=s[i]-k;
                k=0;
            }
            if(k==0) break;
        }

        return s;
    }
};