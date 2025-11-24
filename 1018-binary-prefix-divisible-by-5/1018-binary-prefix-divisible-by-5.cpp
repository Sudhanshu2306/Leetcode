class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        long long x=0;
        for(int i=0;i<nums.size();i++){
            x=(x*2)%5;
            if(nums[i]==1) x++;

            if(x%5==0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};