class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int n=s.size();
        int depth=0;
        int maxi=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
                depth++;
                maxi=max(maxi,depth);
            } 
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                    depth--;
                } 
                else return -1;
            }
        }
        return maxi;
    }
};