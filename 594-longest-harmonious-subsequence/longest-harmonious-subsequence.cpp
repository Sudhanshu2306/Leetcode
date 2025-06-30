class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-1)!=mp.end()) ans=max(ans,mp[nums[i]]+mp[nums[i]-1]);
            if(mp.find(nums[i]+1)!=mp.end()) ans=max(ans,mp[nums[i]]+mp[nums[i]+1]);
        }
        return ans;
    }
};