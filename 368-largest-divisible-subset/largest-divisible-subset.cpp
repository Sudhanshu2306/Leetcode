class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        int maxi=1;
        int lastIndex=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> temp(maxi); temp[0]=nums[lastIndex];
        int ind=1;
        while(lastIndex!=hash[lastIndex]){
            lastIndex=hash[lastIndex];
            temp[ind++]=nums[lastIndex];
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};