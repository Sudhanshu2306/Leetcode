class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.length();
        stack<char> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && k && st.top()>s[i]){
                st.pop();
                k--;
            } 
            if(!st.empty() || s[i]!='0') st.push(s[i]);
        }
        while(!st.empty() && k){
            st.pop();
            k--;
        }
        string ans="";
        if(st.empty()) return "0";
        // if(st.size()==1) return to_string(st.top());

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};