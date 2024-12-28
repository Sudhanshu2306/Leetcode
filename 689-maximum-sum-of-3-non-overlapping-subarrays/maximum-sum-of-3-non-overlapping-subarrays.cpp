class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+nums[i];

        vector<int> left(n,0), right(n,n-k);
        int li=0, ri=n-k;

        for(int i=k;i<n;i++){
            if(pre[i+1]-pre[i-k+1]>pre[li+k]-pre[li] || (pre[i+1]-pre[i-k+1]==pre[li+k]-pre[li] && i-k<li)) li=i-k+1;
            left[i]=li;
        }

        for(int i=n-k-1;i>=0;i--){
            if (pre[i+k]-pre[i]>=pre[ri+k]-pre[ri] || (pre[i+k]-pre[i]==pre[ri+k]-pre[ri] && i<ri)) ri=i;
            right[i]=ri;
        }

        vector<int> result(3,0);
        int maxi=0;
        for(int i=k;i<=n-2*k;i++){
            int l=left[i-1], r=right[i+k];
            int sum=(pre[l+k]-pre[l])+(pre[i+k]-pre[i])+(pre[r+k]-pre[r]);
            if(sum>maxi){
                maxi=sum;
                result={l,i,r};
            }
        }
        return result;
    }
};