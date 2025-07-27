class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0;
        int j=0;
        for(int i=0;i<nums.size()-1;i++){
            if((nums[j]<nums[i] && nums[i]>nums[i+1]) || (nums[j]>nums[i] && nums[i]<nums[i+1])){
                count++; j=i;
            }
        }
        return count;
    }
};