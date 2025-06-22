class Solution {
public:
    int dp[13][1<<12];
    int ff(vector<int> &a, int mask){
        int sum=0;
        for(int i=0;i<a.size();i++){
            if((1<<i) & mask) sum+=a[i];
        }
        return sum;
    }
    int f(int mask,vector<int> &a, int k){
        if(k==1) return ff(a,mask);

        if(dp[k][mask]!=-1) return dp[k][mask];

        int ans=INT_MAX;
        for(int j=mask;j>0;j=(j-1)&mask){
            int x=ff(a,j);

            ans=min(ans,max(x,f(j^mask,a,k-1)));
        }
        return dp[k][mask]=ans;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        memset(dp,-1,sizeof(dp));
        return f((1<<12)-1,jobs,k);
    }
};