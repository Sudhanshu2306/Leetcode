class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector<int> mp(k,0);
        mp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i]%k+k)%k;
            count+=mp[sum];
            mp[sum]++;
        }
        return count;
    }
};