class Solution {
public:
    int f(int i, int j, vector<vector<int>> &dp, vector<int> &a){
        if(j==a.size()) return a[i]; //only a[i] is remaining
        if(j==a.size()-1) return max(a[i],a[j]); // only a[i] && a[j] are remaining
        if(dp[i][j]!=-1) return dp[i][j];
        
        int x=max(a[i],a[j])+f(j+1,j+2,dp,a);
        int y=max(a[i],a[j+1])+f(j,j+2,dp,a);
        int z=max(a[j],a[j+1])+f(i,j+2,dp,a);

        return dp[i][j]=min({x,y,z});

    }
    int minCost(vector<int>& nums) {
        // dp problem for sure
        // we can define dp state dp(i,j) as i represents the last element not removed 
        // and j represents the current starting index
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans=f(0,1,dp,nums);
        return ans;
    }
};