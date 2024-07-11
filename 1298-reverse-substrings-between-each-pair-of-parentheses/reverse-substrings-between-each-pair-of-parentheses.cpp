class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        int n=s.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]==')'){
                int m=st.top(); st.pop();
                int k=i;
                while(m<k){
                    swap(s[m],s[k]);
                    m++;k--;
                }
            }
            else if(s[i]=='('){
                st.push(i);
            } 
        }
        for(int i=0;i<n;i++){
            if(s[i]!='(' && s[i]!=')') ans+=s[i];
        }
        return ans;
    }
};