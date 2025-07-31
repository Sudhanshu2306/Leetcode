class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> st,ans;
        for(auto it:arr){
            set<int> ts; ts.insert(it);
            for(auto itr:st) ts.insert(itr|it);
            st=ts;
            ans.insert(st.begin(),st.end());
        }
        return ans.size();
    }
};