class Solution {
public:
    int f(int i, vector<int> &a, vector<int> &dp){
        int n=a.size();
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];
        // so we are taking state as at ith index, what is the the max value of player 1;
        int maxi=-1e9;
        int sum=0;
        for(int j=0;j<3;j++){
            if(i+j<n) sum+=a[i+j];
            int x=sum-f(i+j+1,a,dp);
            maxi=max(maxi,x);
        }
        return dp[i]=maxi;
    }
    string stoneGameIII(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n+1,-1);

        int alice=f(0,a,dp);
        
        if(alice>0) return "Alice";
        else if(alice<0) return "Bob";
        else return "Tie";
    }
};