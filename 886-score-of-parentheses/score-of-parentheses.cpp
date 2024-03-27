class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int> st;
        int count=0;
        st.push(0);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(0);
            else{
                int temp=st.top();
                st.pop();
                if(temp==0) temp=1;
                else temp=2*temp;
                st.top()+=temp;
            }
            
        }
        return st.top();
    }
};