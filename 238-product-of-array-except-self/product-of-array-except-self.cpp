class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long p=1;
        int flag=0;
        for(int i:nums){
            if(i!=0)
                p*=i;
            else flag++;
        } 

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0 && flag==0)
                nums[i]=p/nums[i];
            else if(nums[i]!=0 && flag>=1) nums[i]=0;
            else if(nums[i]==0 && flag>1) nums[i]=0;
            else if(nums[i]==0 && flag==1) nums[i]=p;
        }
        return nums;
    }
};