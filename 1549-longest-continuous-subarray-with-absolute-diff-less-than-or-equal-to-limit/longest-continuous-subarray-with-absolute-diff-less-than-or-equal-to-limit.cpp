class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int i=0,j=0;
        map<int,int> mp;
        int maxi=INT_MIN;
        while(j<n){
            mp[nums[j]]++;

            while((mp.rbegin()->first-mp.begin()->first) > limit){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};