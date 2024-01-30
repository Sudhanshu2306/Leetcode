class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                    int x=st.top(); st.pop();
                    int y=st.top(); st.pop();
                    int s=0;
                    if(tokens[i]== "+") s = y+x;
                    else if(tokens[i]== "-") s = y-x;
                    else if(tokens[i] == "*") s = y*x;
                    else s = y/x;
                    st.push(s);
            }
            // convert sting s to integer and push
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};