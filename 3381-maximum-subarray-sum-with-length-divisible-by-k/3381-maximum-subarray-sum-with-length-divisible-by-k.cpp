typedef long long ll;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll> pre(n+1);
        pre[0]=0;
        pre[1]=nums[0];
        for(int i=2;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        vector<ll> temp(n+1);
        ll maxi=-1e18;
        for(int i=k;i<=n;i++){
            temp[i]=max(temp[i-k]+(pre[i]-pre[i-k]),(pre[i]-pre[i-k]));
            maxi=max(maxi,temp[i]);
        }
        // return temp[n];
        return maxi;
    }
};