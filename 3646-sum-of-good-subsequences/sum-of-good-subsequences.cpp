#define ll long long
class Solution {
public:

int sum=0;
int mod=1e9+7;
map<pair<int,int>, ll> dp;
ll ff(int i, int prev, vector<int> & a){
    if(i==a.size()) return 0;
    
    // state of dp is the sum of subsequence ending with element x and prev
    if(dp.find({i,prev})!=dp.end()) {
        return dp[{i,prev}];
    }

    ll nottake=ff(i+1,prev,a);
    ll take=0;
    if( prev==-1 || abs(a[i]-prev)==1){
        take=a[i]+ff(i+1,a[i],a);
    }
    return dp[{i,prev}]=(take+nottake)%mod;
    
}
    int sumOfGoodSubsequences(vector<int>& nums) {
        // int prev = -1;
        // ff(0, prev, nums, 0);
        // return sum;
        int n = nums.size();
        vector<ll> x(1e5+7, 0);
        vector<ll> freq(1e5+7, 0);
        
        ll ans = 0;
        for (auto it : nums) {
            ll count = 1, sum = it;
            if (it > 0) count = (freq[it - 1] + count) % mod;
            if (it > 0) sum = (((ll)freq[it - 1] * it + sum + x[it - 1]) % mod) % mod;
            if (it < 1e5+1) count = (freq[it + 1] + count) % mod;
            if (it < 1e5+1) sum = (((ll)freq[it + 1] * it + sum + x[it + 1]) % mod) % mod;
            
            ans = (ans + sum) % mod;
            freq[it] = (freq[it] + count) % mod;
            x[it] = (x[it] + sum) % mod;
        }
        return ans;
    }
};