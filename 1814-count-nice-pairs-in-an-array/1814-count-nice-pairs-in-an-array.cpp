class Solution {
private:
    int rev(int num) {
        int ans = 0;
        while (num > 0) {
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int mod=1e9+7;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-rev(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<n-1;i++){
            long long c=1;
            while(i<n-1 && nums[i]==nums[i+1]){
                c++;
                i++;
            }
            ans=(ans%mod+(c*(c-1))/2)%mod;
        }
        return static_cast<int>(ans);
    }
};