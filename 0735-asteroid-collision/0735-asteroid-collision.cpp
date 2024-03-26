class Solution {
public:
    bool sameSign(int x,int y){
        if((x*y>0)){
            return true;
        }
        else{
            return false;
        }
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;

        for(int i=0;i<asteroids.size();i++){
            if(st.size()==0 || (st.top()<0 && asteroids[i]>0) || sameSign(st.top(),asteroids[i])){
                st.push(asteroids[i]);
            }
            else{
                while(st.size()>0 && st.top()>0 && st.top()<abs(asteroids[i])){
                    st.pop();
                }

                if(st.size()==0 || st.top()<0){
                    st.push(asteroids[i]);
                }
                else if(st.top()==abs(asteroids[i])){
                    st.pop();
                }
            }
        }
        vector<int> ans(st.size());
        int i=st.size()-1;
        while(!st.empty()){
            ans[i]=st.top();
            i--;
            st.pop();
        }
        return ans;
    }
};