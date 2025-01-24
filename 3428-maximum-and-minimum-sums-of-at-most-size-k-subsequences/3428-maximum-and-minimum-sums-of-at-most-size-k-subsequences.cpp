class Solution {
public:
    int mod=1e9+7;
    int minMaxSums(vector<int>& nums, int k) {
        // nCk=(n-1)Ck+(n-1)C(k-1);
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ncr(n+1,vector<int>(k+1,1));
        // base case
        for(int i=0;i<=n;i++) ncr[i][1]=i,ncr[i][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=k && j<i;j++){
                ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
            }
        }

        long long mini=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=min(n,k);j++){
                if(n-i-1>=j-1) mini=(mini+(1ll*nums[i]*ncr[n-i-1][j-1]))%mod;
            }
        }

        long long maxi=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=min(n,k);j++){
                if(i>=j-1) maxi=(maxi+(1ll*nums[i]*ncr[i][j-1]))%mod;
            }
        }
        long long res=mini+maxi;
        return res;
    }
};