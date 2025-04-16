class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long n=nums.size();
        long long i=0,j=0;
        long long prev=0;
        long long ans=0;
        map<long long,long long> mp;
        while(j<n){
            prev+=mp[nums[j]];
            mp[nums[j]]++;

            while(prev>=k){
                ans+=(n-j);
                mp[nums[i]]--; prev-=mp[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};