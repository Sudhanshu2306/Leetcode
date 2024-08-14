class Solution {
public:
    bool f(const vector<int>& nums, int k, int mid) {
        int count=0, left=0;
        for(int i=1;i<nums.size();i++){
            while(nums[i]-nums[left]>mid) left++;
            count+=i-left;
        }
        return count>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n=nums.size();
        int left=0;
        int right=nums[n-1]-nums[0];

        while(left<right){
            int mid=left+(right-left)/2;

            if(f(nums,k,mid)) right = mid;
            else left=mid+1;
        }
        return left;
    }
};