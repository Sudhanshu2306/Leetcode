class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0;
        int maxi=INT_MIN;
        for(int j=0;j<nums.size();j++){
            mp[nums[j]]++;

            for(;mp[nums[j]]>k;i++) mp[nums[i]]--;

            maxi=max(maxi,j-i+1);
        } 
        return maxi;
    }
};