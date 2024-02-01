class Solution {
public:

    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int f(int i, int n, string &s, vector<int> &dp){
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+f(j+1,n,s,dp);
                mini=min(mini,cost);
            } 
        }
        return dp[i]=mini;
    }

    int tabulation(string &s){
        int n=s.length();
        vector<int> dp(n+1,0);

        // base case -> here all the elements are already 0, so base case is already satisfied

        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    int cost=1+dp[j+1];
                    mini=min(mini,cost);
                } 
            }
            dp[i]=mini;
        }
        return dp[0];
    }

    int minCut(string s) {
        // int n=s.length();
        // vector<int> dp(n+1,-1);
        // return f(0,n,s,dp)-1;
        return tabulation(s)-1;
    }
};