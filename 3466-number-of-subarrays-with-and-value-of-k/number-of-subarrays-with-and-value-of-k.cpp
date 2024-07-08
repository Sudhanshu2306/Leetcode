class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long count=0;
        unordered_map<int,long long> temp;
        for(int i=0;i<n;i++){
            unordered_map<int,long long> mp;
            for(auto it:temp){
                int x=it.first&nums[i];
                mp[x]+=it.second;
            }
            mp[nums[i]]++;
            for(auto it:mp) if(it.first==k) count+=it.second;
            temp=mp;
        }
        return count;
    }
};