class Solution {
public:
    bool f(vector<int>&nums, int p, int k){
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]<=k){
                i++;
                count++;
            } 
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        int s=0,e=nums[n-1];
        while(s<=e){
            int mid=s+(e-s)/2;
            if(f(nums,p,mid)){
                e=mid-1;
            }
            else s=mid+1;
        }
        return s;
    }
};