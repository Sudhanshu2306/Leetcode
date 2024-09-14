class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end()); 
        int len=0;
        int maxLen=0; 
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                len++;
                maxLen=max(maxLen,len);
            }
            else len=0;
        }
        return maxLen;
    }
};