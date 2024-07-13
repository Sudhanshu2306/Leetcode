class Solution {
public:
    int f(int i, int j, vector<int> &piles, vector<vector<int>> &dp){
        // base case
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int one=piles[i]+f(i+1,j-1,piles,dp);
        int two=piles[j]+f(i+1,j-1,piles,dp);

        return dp[i][j]=max(one,two);

    }

    bool stoneGame(vector<int>& piles) {
        // return true;
        int n=piles.size();
        int sum=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int alice=f(0,n-1,piles,dp);
        for(auto i:piles)sum+=i;

        if(sum-alice<alice) return true;
        else return false;
    }
};