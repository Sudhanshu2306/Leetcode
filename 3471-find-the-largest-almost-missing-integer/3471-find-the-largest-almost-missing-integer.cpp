class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;

        if(k==nums.size()) return *max_element(nums.begin(),nums.end());

        int maxi=-1e9;
        for(auto it:mp){
            if(it.second==1 && it.first>maxi) maxi=it.first;
        }

        if(k==1){
            if(maxi==-1e9) return -1;
            else return maxi;
        }

        int x=mp[nums[0]], y=mp[nums.back()];
        if(x==1 && y!=1) return nums[0];
        else if(x!=1 && y==1) return nums.back();
        else if(x==1 && y==1) return max(nums[0],nums.back());
        else return -1;
    }
};