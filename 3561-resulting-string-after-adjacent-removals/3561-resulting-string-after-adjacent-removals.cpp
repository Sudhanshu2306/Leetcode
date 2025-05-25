class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && (abs(st.top()-s[i])==1 || (st.top()=='a' && s[i]=='z') || (st.top()=='z' && s[i]=='a'))){
                st.pop();
            }
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top(); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};