class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        auto comp=[&mp](int a,int b){
            if(mp[a]==mp[b]) return a>b;
            return mp[a]<mp[b];
        };
        sort(nums.begin(),nums.end(),comp);
        return nums;
    }
};