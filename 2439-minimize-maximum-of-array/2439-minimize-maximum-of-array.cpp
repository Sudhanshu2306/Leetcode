class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int ind=0;
        int x=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>x){
                x=nums[i];
                ind=i;
            }
        }
        // cout<<nums[ind];
        if(ind==0) return nums[0];
        if((nums[ind]-nums[ind-1])==1) return nums[ind];
        if((nums[ind]-nums[ind-1])%2==0){
            long long a=(nums[ind]+nums[ind-1])/2;
            return (int)a;
        }
        else{
            long long a=(nums[ind]+nums[ind-1])/2;
            return (int)a;
        }
    }
};