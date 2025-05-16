class Solution {
public:
    int mod=1e9+7;
    int dp[3001][301][4];
    int f(int i, vector<int> &arr, const int &target, int k){
        if(k==0) return target==0;
        if(i<0) return 0;

        if(dp[i][target][k]!=-1) return dp[i][target][k];

        int take=0;
        if(target>=arr[i]) take=f(i-1,arr,target-arr[i],k-1);
        int nottake=f(i-1,arr,target,k);

        return dp[i][target][k]=(nottake+take)%mod;
    }
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        memset(dp, -1, sizeof(dp));
        int ans=f(n-1,arr,target,3);
        return ans;
    }
};