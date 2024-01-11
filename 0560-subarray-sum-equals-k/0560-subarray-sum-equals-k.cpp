class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        
        unordered_map<int,int> mp;
        mp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int x=sum-k;
            if(mp.find(x)!=mp.end()) count+=mp[x];
            mp[sum]++;
        }
        return count;
    }
};