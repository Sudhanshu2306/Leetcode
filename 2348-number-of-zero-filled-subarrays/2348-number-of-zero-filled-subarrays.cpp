class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long  x=0;
        long long  count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count++;
            else{
                x+=(1LL*count*(count+1))/2;
                count=0;
            }
        }
        if(count>0) x+=(1LL*count*(count+1))/2;
        return x;
    }
};