class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size()-1;i++){
            double x=nums[i-1]+nums[i+1];
            double y=nums[i]/2.0;
            
            if(x==y) count++;
        }
        return count;
    }
};