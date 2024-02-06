class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1;
        while(j<n){
            if(i-1>=0){
                if(nums[i]==nums[j] && nums[j]==nums[i-1]){
                    j++;
                }
                else{
                    i++;
                    nums[i]=nums[j];
                    j++;
                }
            }
            else{
                i++;
                j++;
            } 
        }
        return i+1;
    }
};