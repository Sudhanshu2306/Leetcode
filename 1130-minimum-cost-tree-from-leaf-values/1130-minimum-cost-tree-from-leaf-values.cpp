class Solution {
public:
    int dp[45][45];
    int f(int i, int j, vector<int> &a){
        if(i>=j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        long long ans=1e9;
        for(int k=i;k<j;k++){
            int left=*max_element(a.begin()+i,a.begin()+k+1);
            int right=*max_element(a.begin()+k+1,a.begin()+j+1);
            ans=min(ans,1LL*left*right+f(i,k,a)+f(k+1,j,a));
        }
        return dp[i][j]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,arr);
    }
};