class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<int> diff;
        for(auto it:nums){
            diff.push_back((it^k)-it);
        }
        sort(diff.rbegin(),diff.rend());
        long long ans=accumulate(nums.begin(),nums.end(),0LL);
        for(int i=0;i<n;i+=2){
            if(i==n-1) break;
            int d=diff[i]+diff[i+1];
            if(d>0) ans+=d;
        }
        return ans;
    }
};