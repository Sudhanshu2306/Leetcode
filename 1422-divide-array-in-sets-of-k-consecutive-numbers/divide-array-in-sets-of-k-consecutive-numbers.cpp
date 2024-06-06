class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return 0;

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        sort(nums.begin(),nums.end());

        for(auto i:nums){
            if(mp[i]){
                for(int j=i;j<i+k;j++){
                    if(mp[j]--<=0) return 0;
                }
            }
        }
        return 1;
    }
};