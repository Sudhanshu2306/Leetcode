class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        if(nums[0]>0) count++;
        // also if size bada h max element se toh
        if(nums.back()<nums.size()) count++;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<i+1 && nums[i+1]>i+1) count++;
        }
        return count;
    }
};