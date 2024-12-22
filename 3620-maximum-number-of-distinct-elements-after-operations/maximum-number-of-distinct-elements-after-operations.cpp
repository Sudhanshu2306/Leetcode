class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int prev=-2e9+100;
        int count=0;
        for(int i=0;i<nums.size();i++){
            int x=max(nums[i]-k,prev+1);
            if(x<=nums[i]+k){
                count++; prev=x;
            }
        }
        return count;
    }
};