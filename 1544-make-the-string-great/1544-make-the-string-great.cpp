class Solution {
public:
    string makeGood(string s) {
        string ans="";
        int n=s.size();
        stack<char> st;
        st.push(s[n-1]);
        for(int i=n-2;i>=0;i--){
            if(!st.empty() && s[i]!=st.top() && abs(s[i]-st.top())==32) st.pop();
            else st.push(s[i]);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};