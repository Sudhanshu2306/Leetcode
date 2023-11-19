class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        int prev=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=prev){
                ans+=(n-i);
                prev=nums[i];
            }
        }
        return ans;
    }
};