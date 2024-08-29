class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else if(s[i]==']'){
                string x="";
                while(st.top()!='['){
                    x+=st.top(); st.pop();
                }
                reverse(x.begin(),x.end());
                st.pop();
                string num="";
                while(!st.empty() && isdigit(st.top())){
                    num+=st.top(); st.pop();
                }
                reverse(num.begin(),num.end());
                int a=stoi(num);
                while(a--){
                    for(auto ch:x) st.push(ch);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top(); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};