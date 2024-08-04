class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // sort(nums.begin(),nums.end());
        int mod=1e9+7;
        vector<int> sumArr;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum=(sum+nums[j])%mod;
                sumArr.push_back(sum);
            }
        }
        sort(sumArr.begin(),sumArr.end());
        left--; right--;

        int ans=0;
        for(int i=left;i<=right;i++){
            ans=(ans+sumArr[i])%mod;
        }
        return ans;
    }
};