class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long sum=1;
        int ans=0;
        int i=0;
        while(sum<=n){
            if(i<nums.size() && nums[i]<=sum){
                sum+=nums[i];
                i++;
            }
            else{
                sum+=sum;
                ans++;
            }
        }
        return ans;
    }
};