class Solution {
public:
    bool ff(vector<int> nums, int s, int e){
        for(int i=s;i<e-1 && i+1<nums.size();i++){
            if(nums[i]>=nums[i+1]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==2 && k==1) return true;
        for(int i=0;i<n-2*k+1;i++){
            if(ff(nums,i,i+k) && ff(nums,i+k,i+2*k)) return true;
        }
        return false;
    }
};