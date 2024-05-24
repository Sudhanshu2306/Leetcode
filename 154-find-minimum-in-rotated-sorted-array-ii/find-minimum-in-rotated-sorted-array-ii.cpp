class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        // if(n==1) return nums[0];
        int i=0,j=n-1;
        int ans=INT_MAX;
        while(i<=j){
            int mid=i+(j-i)/2;

            if(mid+1<n && mid-1>=0 && nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]) return nums[mid];

            if(nums[mid]==nums[i] && nums[mid]==nums[j]){
                ans=min(ans,nums[mid]);
                i++; j--;
                continue;
            }

            if(nums[mid]>=nums[i]){
                ans=min(ans,nums[i]);
                i=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                j=mid-1;
            } 
        }
        return ans;
    }
};