class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=nums.size();
        vector<long long> ans(n,0);

        set<pair<long long,long long>> st;
        map<long long,long long> m;
        for(int i=0;i<nums.size();i++){
            auto temp=st.find({m[nums[i]],nums[i]});
            if(temp!=st.end()) st.erase(temp);
            m[nums[i]]+=freq[i];
            
            st.insert({m[nums[i]],nums[i]});
            ans[i]=st.rbegin()->first;
        } 
        return ans;
    }
};