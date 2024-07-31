class Solution {
public:
    int f(int ind, int shelfWidth, vector<vector<int>>& books, vector<int>& dp){
        if(ind>=books.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];
        int sum=0; int maxi=0;
        int ans=1e9;
        for(int i=ind;i<books.size();i++){
            sum+=books[i][0];
            maxi=max(maxi,books[i][1]);
            if(sum<=shelfWidth) ans=min(ans,f(i+1,shelfWidth,books,dp)+maxi);
        }
        return dp[ind]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> dp(n,-1);
        return f(0,shelfWidth,books,dp);
    }
};