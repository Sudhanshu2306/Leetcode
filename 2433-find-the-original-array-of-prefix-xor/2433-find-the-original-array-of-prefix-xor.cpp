class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size());
        ans[0]=pref[0];
        for(int i=0;i<pref.size()-1;i++){
            ans[i+1]=pref[i]^pref[i+1];
        }
        return ans;
    }
};