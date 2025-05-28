class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        st.push(n-1);
        vector<int> ans(n);
        ans[n-1]=0;
        // int flag=1;
        for(int i=n-2;i>=0;i--){
            // int count=0;
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i]=0;
            else ans[i]=st.top()-i;

            st.push(i);
        }
        return ans;
    }
};