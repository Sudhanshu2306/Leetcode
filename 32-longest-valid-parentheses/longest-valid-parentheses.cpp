class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        if(n==0) return 0;
        // tried storing char i.e '(' and ')', but it didn't work out, so start storing index
        stack<int> st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty()) st.pop();
                if(st.empty()) st.push(i);
                else{
                    maxi=max(maxi,i-st.top());
                }
            }
        }
        return maxi;
    }
};