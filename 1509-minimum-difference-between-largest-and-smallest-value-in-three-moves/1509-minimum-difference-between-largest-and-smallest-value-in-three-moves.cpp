class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());

        int maxi=INT_MAX;
        for(int i=0;i<4;i++){
            int x=3-i;
            maxi=min(maxi,nums[n-x-1]-nums[i]);
        }
        return maxi;
    }
};