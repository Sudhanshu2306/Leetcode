class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int> st;

        int open=0, close=0;
        for(int i=0;i<n;i++){
            if(s[i]==')' && !st.empty() && s[st.top()]=='('){
                st.pop();
            }
            else if(s[i]=='(' || s[i]==')'){
                st.push(i);
            }
        }

        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }
        string ans="";
        for(auto ch:s){
            if(ch!='#') ans+=ch;
        }

        return ans;
    }
};