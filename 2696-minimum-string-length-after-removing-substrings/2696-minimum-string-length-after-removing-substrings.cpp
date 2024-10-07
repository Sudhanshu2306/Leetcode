class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        stack<char> st;
        for(auto ch:s){
            if(!st.empty() && ((st.top()=='A' && ch =='B') || (st.top()=='C' && ch=='D'))) {
                st.pop();
            }
            else st.push(ch);
        }
        return st.size();
    }
};