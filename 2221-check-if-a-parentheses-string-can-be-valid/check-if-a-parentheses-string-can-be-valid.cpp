class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(locked[i]=='0') s[i]='*';
        }

        stack<int> st, x;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]=='*') x.push(i);
            else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else if(!x.empty()) x.pop();
                else return false;
            }
        }
        while(!st.empty() && !x.empty() && st.top()<x.top()){
            st.pop(); x.pop();
        }
        if(x.size()%2==1) return false;
        return st.empty();
    }
};