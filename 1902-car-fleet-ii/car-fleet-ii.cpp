class Solution {
public:

    /*remember: I tried using stack with pair that stores the values as given in vector cars, 
    but the problem then arised was i cannot access index with this stack, so we store index in stack, 
    which is by far best way to deal with questions in stack */

    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n=cars.size();
        vector<double> ans(n,(double)-1);
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && (cars[i][1]<=cars[st.top()][1])) st.pop();

            while(!st.empty()){
                double t=((cars[st.top()][0]-cars[i][0])*1.0)/(cars[i][1]-cars[st.top()][1]);
                // even after getting the ans, check for minimum possible time to bypass any car
                if(ans[st.top()]==-1 || t<=ans[st.top()]){
                    ans[i]=t; break;
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};