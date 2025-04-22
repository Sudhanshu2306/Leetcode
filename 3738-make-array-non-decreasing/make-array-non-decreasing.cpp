class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int count=1;
        int prev=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>=prev){
                count++;
                prev=nums[i];
            }
        }
        return count;
    }
};