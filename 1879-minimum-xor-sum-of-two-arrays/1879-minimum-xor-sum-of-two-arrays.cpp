class Solution {
public:
    int dp[1<<14];
    int f(int mask, vector<int> &a, vector<int> &b){
        int i=__builtin_popcount(mask);
        if(i==a.size()) return 0;            
        if(dp[mask] != -1) return dp[mask];
        int best=INT_MAX;
        for(int j=0;j<b.size();j++){
            if(!(mask&(1<<j))) {
                int cur=(a[i]^b[j])+f(mask|(1<<j),a,b);
                best=min(best,cur);
            }
        }
        return dp[mask]=best;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        memset(dp,-1,sizeof(dp));
        return f(0,nums1,nums2);
    }
};