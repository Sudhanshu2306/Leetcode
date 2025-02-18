class Solution {
public:
    string smallestNumber(string s) {
        stack<int> st;
        // continuous I's par increasing and then reverse the flow on getting D
        int n=s.size();
        string ans="";
        for(int i=0;i<=n;i++){
            st.push(i+1);
            if(i==n || s[i]=='I'){
                while(!st.empty()){
                    ans+=to_string(st.top()); st.pop();
                }
            }
        }
        return ans;
    }
};