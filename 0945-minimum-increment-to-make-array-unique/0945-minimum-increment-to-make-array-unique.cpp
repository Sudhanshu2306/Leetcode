class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                int x=abs(nums[i]-nums[i-1])+1;
                count+=x;
                nums[i]+=x;
            }
        }
        return count;
    }
};