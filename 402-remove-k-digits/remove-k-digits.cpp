class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<int> st;
        int n=s.size();
        if(k>=n) return "0";
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && s[st.top()]>s[i]){
                st.pop(); k--;
            }
            st.push(i);
        }
        while(k--){
            st.pop();
        }
        string ans="";
        while(!st.empty()){
            ans+=s[st.top()]; st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0') i++;
        if(ans.substr(i)=="") return "0";
        return ans.substr(i);
    }
};