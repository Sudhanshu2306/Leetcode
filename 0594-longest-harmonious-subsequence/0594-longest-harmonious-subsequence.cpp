class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        map<int,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            auto [u,v]=mp[nums[i]];
            mp[nums[i]]={min(u,i),max(v,i)};
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-1)!=mp.end()){
                ans=max({ans,abs(i-mp[nums[i]-1].first),abs(i-mp[nums[i]-1].second)});
            }
            if(mp.find(nums[i]+1)!=mp.end()){
                ans=max({ans,abs(i-mp[nums[i]+1].first),abs(i-mp[nums[i]+1].second)});
            }
        }
        return ans?ans-1:0;
    }
};