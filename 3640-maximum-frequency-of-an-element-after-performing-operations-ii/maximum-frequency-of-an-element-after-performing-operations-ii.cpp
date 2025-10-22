class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int nop) {
        map<int,int>mp;
        unordered_map<int,int> hash;
        set<int> st;
        for(auto &it:nums){
            hash[it]++;
            mp[it-k]++;
            mp[it+k+1]--;
            st.insert(it);
            st.insert(it-k);
            st.insert(it+k+1);
        }
        int ans=1;
        int sum=0;
        for(auto &it:st){
            sum+=mp[it];
            ans=max(ans,hash[it]+min(sum-hash[it],nop));
        }
        return ans;
    }
};