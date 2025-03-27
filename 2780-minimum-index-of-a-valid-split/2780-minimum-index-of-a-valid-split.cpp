class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int> mp,pm;
        for(auto it:nums) mp[it]++;

        for(int i=0;i<nums.size();i++){
            int a=--mp[nums[i]];
            int b=++pm[nums[i]];

            if(a*2>(nums.size()-i-1) && b*2>(i+1)) return i;
        }
        return -1;
    }
};