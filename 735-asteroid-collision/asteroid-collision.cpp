class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int n=a.size();
        for(int i=0;i<n;i++){
            bool flag=false;
            while(!st.empty() && st.top()>0 && a[i]<0){
                if(st.top()==abs(a[i])){
                    st.pop(); flag=true; break;
                } 
                else if(st.top()>abs(a[i])){
                    flag=true; break;
                }
                else st.pop();
            }
            if(!flag) st.push(a[i]);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};