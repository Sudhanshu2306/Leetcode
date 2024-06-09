class Solution {
public:
    long long minSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        for(int i:nums) sum+=i;

        int rem=sum%k;
        if(rem==0) return 0;

        unordered_map<long long,long long> mp; // to map rem with index
        mp[0]=-1;
        long long tot=0;
        long long mini=n;
        for(long long i=0;i<n;i++){
            tot+=nums[i];
            long long curr=tot%k;

            long long req=(curr-rem+k)%k;
            if(mp.find(req)!=mp.end()){
                mini=min(mini,i-mp[req]);
            }
            mp[curr]=i;
        }
        return mini==n?-1:mini;
    }
};