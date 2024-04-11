class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.length();
        stack<char> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>s[i] && k>0){
                st.pop();
                k--;
            }
            // zero can only be added when there exists some number in the stack, to avoid leading zeros
            if(!st.empty() || s[i]!='0'){
                st.push(s[i]);
            }
        }
        // this will only execute when k is remaining even after 1st loop.
        while(!st.empty() && k){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
    
        string result = "";
        while (!st.empty()) {
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};