class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==','){continue;}
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                int t=0,f=0;
                char ch;
                while(st.top()!='('){
                    if(st.top()=='t'){t++;}
                    if(st.top()=='f'){f++;}
                    st.pop();
                }
                st.pop();
                ch=st.top();st.pop();
                if(ch=='!'){
                    if(t){st.push('f');}
                    else st.push('t');
                }
                else if(ch=='&'&&f>0){st.push('f');}
                else if(ch=='|'&&t==0){st.push('f');}
                else st.push('t');
            }
        }
        return (st.top()=='t');
    }
};