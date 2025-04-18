class Solution {
public:
    string countAndSay(int n) {
        string x="1";
        if(n==1) return x;
        
        for(int i=2;i<=n;i++){
            string y="";
            int count=1;
            char ch=x[0];
            for(int j=1;j<x.size();j++){
                if(x[j]==ch){
                    count++; 
                }
                else{
                    y+=to_string(count);
                    y+=ch;
                    ch=x[j];
                    count=1;
                } 
            }
            y+=to_string(count);
            y+=ch;
            x=y;
            cout<<x<<" ";
        }
        return x;
    }
};