class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int count=0;
        for(auto it:nums){
            while(!st.empty() && it<st.top()) st.pop();
            if(st.empty() || it>st.top()){
                if(it!=0) count++;
                st.push(it);
            }
        }
        return count;
    }
};