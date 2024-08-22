class Solution {
public:
    int f(int i, int prev, vector<int> &arr, vector<vector<int>> &dp, int x){
        int n=arr.size();
        if(i>=n) return 0;

        if(dp[i][prev]!=-1) return dp[i][prev];

        int mini=min(arr[i]-arr[prev],x);

        if(i<n-1) mini+=f(i+2,i+1,arr,dp,x);
        if(i<n-1) mini=min(mini,f(i+2,prev,arr,dp,x)+arr[i+1]-arr[i]);

        return dp[i][prev]=mini;
    }

    int minOperations(string s1, string s2, int x) {
        int n=s1.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<int> arr;

        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) arr.push_back(i);
        }
        if(arr.size()&1) return -1;
        return f(1,0,arr,dp,x);
    }
};