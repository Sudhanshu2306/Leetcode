class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        map<int,int> mp;
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.rbegin()->first-mp.begin()->first>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};