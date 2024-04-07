class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int maxi=1;

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                ans++;
                maxi=max(maxi,ans);
            }
            else ans=1;
        }
        ans=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                ans++; 
                maxi=max(maxi,ans);
            }
            else ans=1;
        }
        return maxi;
    }
};