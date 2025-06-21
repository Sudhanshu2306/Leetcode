class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int count=0, curr=0;
        for(int i=0;i<nums.size();i++){
            if(curr==0){
                curr=nums[i]; 
            }
            else curr=curr&nums[i];
            if(curr==0) count++;
        }
        return max(1,count);
    }
};