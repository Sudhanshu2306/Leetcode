class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int x=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            x+=nums[i];
            if(x==0) count++;
        }
        return count;
    }
};