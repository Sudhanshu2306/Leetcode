class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(1000001,0);
        dp[nums[0]]=1;dp[nums[0]+1]=1;
        
        for(int i=1;i<nums.size();i++){

            dp[nums[i]+1]=max(dp[nums[i]+1],dp[nums[i]]+1);
            if(nums[i]!=0){
                dp[nums[i]]=max(dp[nums[i]],dp[nums[i]-1]+1);
            }
        }
        int x=*max_element(dp.begin(),dp.end());
        return x;
    }
};