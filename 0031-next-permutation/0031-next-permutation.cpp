class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // narayana padita algorithm
        // finding peak algorithm
        int n=nums.size();
        int pi;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                pi=i;
                break;
            }
        }
        
        //swapping
        if(pi!=0){
            for(int i=n-1;i>=pi;i--){
                if(nums[i]>nums[pi-1]){
                    swap(nums[i],nums[pi-1]);
                    break;
                }
            }
        }
        
        // reversing the order
        for(int i=n-1;i>pi;i--,pi++){
            swap(nums[i],nums[pi]);
        }
    }
};