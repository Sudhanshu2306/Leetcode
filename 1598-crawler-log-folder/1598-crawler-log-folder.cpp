class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(auto i:logs){
            if(!st.empty() && i=="../") st.pop();
            else if(i=="./"){
            
            }
            else{
                st.push(i);
            }
        }
        return st.size();
    }
};