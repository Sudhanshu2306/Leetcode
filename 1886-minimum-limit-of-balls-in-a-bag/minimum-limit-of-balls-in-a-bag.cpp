class Solution {
public:

    bool ff(vector<int> &nums, int maxOperations, int mid){
        int x=0;
        for(int i=0;i<nums.size();i++) x+=(nums[i]+mid-1)/mid -1;
        return x<=maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int s=1,e=1e9;
        int ans=0;
        
        while(s<=e){
            int mid=s+(e-s)/2; // mid is the maximum size of bag
            if(ff(nums,maxOperations,mid)){
                ans=mid; e=mid-1;
            } 
            else s=mid+1;
        }
        return ans;
    }
};