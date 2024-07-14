class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // narayana padita algorithm
        int n=nums.size();
        int pi;
        //finding peak index
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                pi=i; break;
            }
        }
        // from end find the element that is just greater than peak index value
        if(pi!=0){
            for(int i=n-1;i>=pi;i--){
                if(nums[i]>nums[pi-1]){
                    swap(nums[i],nums[pi-1]); 
                    break;
                }
            }
        }

        // reverse the order
        for(int i=n-1;i>pi;i--){
            swap(nums[i],nums[pi]);
            pi++;
        }
    }
};