class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;

        int n=nums.size();

        for(auto i:nums) mp[i]++;
        int k=mp.size();
        mp.clear();
        
        int i=0;int j=0;
        int count=0;
        int ans=0;

        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]==1){
                count++;
            }
            while(count==k){
                // ans++;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) count--;
                i++;
            }
            ans+=i;
            j++;
        }
        return ans;
    }
};