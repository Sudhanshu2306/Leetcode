class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;

        for(int i=0;i<a.size();i++){
            int flag=0;
            while(!st.empty() && st.top()>0 && a[i]<0) {
                if(st.top()==-a[i]){
                    st.pop();
                    flag=1;
                    break;
                }
                else if(st.top()>-a[i]){
                    flag=1;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(flag==0) st.push(a[i]); 
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};