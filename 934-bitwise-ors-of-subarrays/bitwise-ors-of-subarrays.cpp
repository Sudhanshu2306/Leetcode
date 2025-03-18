class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> x;
        set<int> st;
        for(auto it:arr){
            set<int> ts;
            ts.insert(it);
            for(auto itr:st) ts.insert(it|itr);
            st=ts;
            for(auto itr:st) x.push_back(itr);
        }
        return set(x.begin(),x.end()).size();
    }
};