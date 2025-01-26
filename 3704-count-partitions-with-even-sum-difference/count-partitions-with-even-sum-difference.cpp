class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long n=nums.size();
        long long sum=0;
        long long count=0;
        long long total=accumulate(nums.begin(),nums.end(),0LL);
        for(long long i=0;i<n-1;i++){
            sum+=nums[i];
            if(abs(total-sum-sum)%2==0) count++;
        }
        return count;
    }
};