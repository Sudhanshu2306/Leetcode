class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int size=nums.size();
        int l=0;
        int r=size-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;

            if(mid>0 && mid<size-1)
            {
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                    return mid;
                else if(nums[mid+1]>nums[mid])
                    l=mid+1;
                else if(nums[mid-1]>nums[mid])
                    r=mid-1;
            }
            else if(mid==0){
                if(nums[0]>nums[1])
                    return 0;
            }
            else if(mid==size-1){
                if(nums[size-1]>nums[size-2])
                    return size-1;
            }
        }
        return -1;
    }
};