class Solution {
public:
    
    bool f(vector<int> &nums, long double p, int i, long long target){
        if(i>=nums.size()) return false;
        if(p==target) return true;
        int take=f(nums,p*nums[i],i+1,target);
        int nottake=f(nums,p,i+1,target);

        return take | nottake;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        long double p=1;
        for(auto it:nums){
            p*=it;
        }
        if(sqrt(p)!=target) return false;

        return f(nums,1,0,target);
    }
};