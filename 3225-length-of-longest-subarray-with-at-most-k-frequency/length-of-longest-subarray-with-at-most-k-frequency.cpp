class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0,j=0;
        int maxi=INT_MIN;
        while(j<nums.size()){
            mp[nums[j]]++;

            while(mp[nums[j]]>k && i<=j){
                mp[nums[i]]--; i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        } 
        return maxi;
    }
};