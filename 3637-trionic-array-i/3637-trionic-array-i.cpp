class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=1;i<n;i++){
            if(nums[i]<=nums[i-1]) break;
        }
        if(i==1 || i==n) return false;
        int x=i;
        for(;i<n;i++){
            if(nums[i]>=nums[i-1]) break;
        }
        if(i==x || i==n) return false;
        x=i;
        for(;i<n;i++){
            if(nums[i]<=nums[i-1]) break;
        } 
        return i==n;
    }
};