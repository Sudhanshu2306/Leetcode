class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k,0);
        vector<long long> dp(k,0);
        for(auto it:nums){
            vector<long long> temp(k,0);
            for(int i=0;i<k;i++){
                temp[(1LL*i*it)%k]+=dp[i];
                ans[(1LL*i*it)%k]+=dp[i];
            }
            dp=temp;
            dp[it%k]++; ans[it%k]++;
        }
        return ans;
    }
};