class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> pre(n,0);
        vector<long long> suf(n,0);
        
        // pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=nums[i-1] | pre[i-1];
        }

        // suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=nums[i+1] | suf[i+1];
        }

        long long maxi=INT_MIN;

        for(int i=0;i<n;i++){
            long long x=nums[i];
            x<<=k;
            x|=pre[i]; x|=suf[i];
            maxi=max(maxi,x);
        }
        return maxi;
    }
};