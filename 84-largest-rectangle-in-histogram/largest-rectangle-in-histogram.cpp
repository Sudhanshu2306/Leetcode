class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        stack<int> st;
        int maxi=0;
        
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || a[st.top()]>=a[i])){
                int curr=a[st.top()]; st.pop();
                int w;
                if(st.empty()) w=i;
                else w=i-st.top()-1;
                maxi=max(maxi,w*curr);
            }
            st.push(i);
        }
        
        return maxi;
    }
};