class Solution {
public:
    bool checkValidString(string s) {
        // 2 loop kar lo, ek baar * ko '(' aur ek baar ')' maan ke

        stack<char> st;
        int n=s.size();
        // * = "("
        bool flag=true;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='*'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()) st.pop();
                else{
                    flag=false;
                    break;
                } 
            }
        }
        
        if(!st.empty()) flag=false;
        
        bool flag1=true;
        stack<char> st1;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st1.push(s[i]);
            }
            else{
                if(!st1.empty()) st1.pop();
                else{
                    flag1=false;
                    break;
                } 
            }
        }
        if(!st1.empty()) flag1=false;

        bool flag2=true;
        stack<char> st2;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st2.push(s[i]);
            }
            else if(s[i]==')'){
                if(!st2.empty()) st2.pop();
                else{
                    flag2=false;
                    break;
                } 
            }
        }
        if(!st2.empty()) flag2=false;

        return flag||flag1||flag2;
    }
};