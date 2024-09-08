using ll=long long;
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ll n=nums.size();
        ll s=0; 
        // ll e=1;
        ll ans=0;
        while(s<n-1){
            ll e=s+1;
            while(e<n && nums[e]<=nums[s]) e++;
            if(e>=n) e=n-1;

            ans+=nums[s]*(e-s);
            s=e;
            // e=s+1;
            // cout<<ans<<" ";
        }
        return ans;
    }
};