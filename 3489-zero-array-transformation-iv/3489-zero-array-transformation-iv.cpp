class Solution {
public:
    int f(int x, int ind, vector<vector<int>> &q, int y, vector<vector<int>> &dp){
        if(x==0) return y;
        if(x<0) return 1e9;
        if(y>=q.size()) return 1e9;

        if(dp[x][y]!=-1) return dp[x][y];
        int not_take=f(x,ind,q,y+1,dp);
        int take=1e9;
        if(q[y][0]<=ind && ind<=q[y][1]) take=f(x-q[y][2],ind,q,y+1,dp);
        return dp[x][y]=min(take,not_take);
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=-1;
        int n=nums.size();
        int m=queries.size();
        for(int i=0;i<n;i++){
            vector<vector<int>> dp(nums[i]+1,vector<int>(m+1,-1));
            ans=max(ans,f(nums[i],i,queries,0,dp));
        }
        if(ans>m) return -1;
        else return ans;
    }
};