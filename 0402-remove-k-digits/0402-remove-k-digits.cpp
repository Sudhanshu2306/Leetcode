class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && s[i]<st.top()){
                st.pop(); k--;
            }
            if(!st.empty() || s[i]!='0')
                st.push(s[i]);
        }
        
        while(!st.empty() && k){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
    
        // string result = "";
        while (!st.empty()) {
            s[n-1]=st.top(); n--;
            st.pop();
        }

        return s.substr(n);
    }
};