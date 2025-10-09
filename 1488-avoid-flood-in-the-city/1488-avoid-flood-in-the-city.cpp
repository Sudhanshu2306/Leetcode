class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int> ans(n,-1);
        map<int,int> mp;
        set<int> st;
        for(int i=0;i<n;i++){
            if(rains[i]>0){
                if(mp.find(rains[i])!=mp.end()){
                    auto it=st.lower_bound(mp[rains[i]]);
                    if(it==st.end()) return {};
                    ans[*it]=rains[i];
                    st.erase(it);
                }
                mp[rains[i]]=i;
            }
            else{
                st.insert(i);
            }
        }
        for(auto it:st) ans[it]=1;
        return ans;
    }
};