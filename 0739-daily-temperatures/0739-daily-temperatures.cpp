class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<int> st;
        vector<int> ans(n);
        ans[n-1]=0; st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && t[st.top()]<=t[i]){
                st.pop(); 
            } 
            if(st.empty()) ans[i]=0;
            else ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    }
};