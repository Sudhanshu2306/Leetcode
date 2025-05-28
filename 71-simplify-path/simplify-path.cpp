class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='/') continue;

            string temp="";
            while(i<n && s[i]!='/'){
                temp+=s[i]; i++;
            }
            if(temp==".") continue;
            else if(temp==".."){
                if(!st.empty()) st.pop();
            }
            else st.push(temp);
        }
        while(!st.empty()){
            ans="/"+st.top()+ans; st.pop();
        }
        if(ans=="") return "/";
        return ans;
    }
};