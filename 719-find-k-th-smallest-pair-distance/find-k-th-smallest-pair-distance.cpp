class Solution {
public:
    bool f(vector<int> &nums, int mid, int k){
        int count=0;
        int i=0;
        for(int j=1;j<nums.size();j++){
            while(nums[j]-nums[i]>mid) i++;
            count+=(j-i);
        }
        return count>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi=nums.back(), mini=nums[0];

        int s=0, e=maxi-mini;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(f(nums,mid,k)) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};