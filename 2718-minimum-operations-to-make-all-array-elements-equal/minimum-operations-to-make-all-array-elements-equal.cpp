class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        vector<long long> ans;
        sort(nums.begin(),nums.end());
        vector<long long> pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }

        for(auto it:queries){
            int x=upper_bound(nums.begin(),nums.end(),it)-nums.begin();

            long long left=1LL*it*x-pre[x];
            long long right=(pre[n]-pre[x])-1LL*it*(n-x);
            ans.push_back(left+right);
        }
        return ans;
    }
};