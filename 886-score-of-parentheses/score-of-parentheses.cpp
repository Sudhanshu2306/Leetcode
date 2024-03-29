class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        stack<int> st;
        st.push(0);

        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(0);
            else{
                int temp=st.top();
                st.pop();
                temp==0?temp=1:temp*=2;
                st.top()+=temp;
            }
        }

        return st.top();
    }
};