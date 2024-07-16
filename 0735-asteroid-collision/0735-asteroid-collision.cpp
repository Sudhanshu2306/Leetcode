class Solution {
public:
    bool ss(int x, int y){
        if(x*y>0) return true;
        else return false;
    }
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;

        for(int i=0;i<a.size();i++){
            if(st.empty() || ss(st.top(),a[i]) || (st.top()<0 && a[i]>0)){
                st.push(a[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(a[i])){
                    st.pop();
                }
                if(st.empty() || st.top()<0){
                    st.push(a[i]);
                }
                else if(abs(st.top())==abs(a[i])){
                    st.pop();
                }
                
            }
        }
        int x=st.size();
        vector<int> ans(x);
        int i=0;
        while(!st.empty()) {
            ans[x-i-1]=(st.top());
            st.pop();
            i++;
        }
        return ans;
    }
};