class Solution {
    int mod=1e9+7;
public:
    int f(int m, int n, int maxMoves, int startRow, int startColumn, vector<vector<vector<int>>> &dp){
        if((startRow<0 || startColumn<0||startRow==m || startColumn==n)){
            return 1;
        }
        if(maxMoves<=0) return 0;

        if(dp[startRow][startColumn][maxMoves]!=-1) return dp[startRow][startColumn][maxMoves];
        long long count=0;
        count+= f(m,n,maxMoves-1,startRow,startColumn-1,dp);
        count+= f(m,n,maxMoves-1,startRow,startColumn+1,dp);
        count+= f(m,n,maxMoves-1,startRow-1,startColumn,dp);
        count+= f(m,n,maxMoves-1,startRow+1,startColumn,dp);

        return dp[startRow][startColumn][maxMoves]=count%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return f(m,n,maxMove,startRow,startColumn,dp);
    }
};