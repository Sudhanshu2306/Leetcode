class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        // 555 -> "555"

        int n=s.size(); 
        bool flag=true;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                flag=false; break;
            }
        }
        if(flag){
            string ans="";
            for(int i=0;i<n;i++) ans+="8";
            return stoi(ans);
        }
        else{
            char c1=s[0];
            string b="";
            if(s[0]!='1'){
                for(int i=0;i<n;i++){
                    if(s[i]==c1) b+="1";
                    else b+=s[i];
                }
            }
            else{
                char ch;
                for(int i=0;i<n;i++){
                    if(s[i]!=c1 && s[i]!='0'){
                        ch=s[i]; break;
                    }
                }
                for(int i=0;i<n;i++){
                    if(s[i]==ch) b+="0";
                    else b+=s[i];
                }
            }
            
            char c;
            for(int i=0;i<n;i++){
                if(s[i]!='9'){
                    c=s[i]; break;
                }
            }
            string a="";
            for(int i=0;i<n;i++){
                if(s[i]==c) a+="9";
                else a+=s[i];
            }
            cout<<stoi(a)<<" "<<stoi(b);
            return stoi(a)-stoi(b);
        }
    }
};