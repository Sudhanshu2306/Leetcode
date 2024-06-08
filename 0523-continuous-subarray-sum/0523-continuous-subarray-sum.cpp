class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> mp;
        int prev=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            sum%=k;
            if(mp[sum]) return true;
            mp[prev]++;
            prev=sum;
        }
        return false;
    }
};