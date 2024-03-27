class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int p=1;
        int j=0;
        for(int i=0;i<nums.size();i++){
            p*=nums[i];

            while(p>=k && j<i){
                p/=nums[j];
                j++;
            }
            if(p<k) ans+=(i-j+1);
        }
        return ans;
    }
};