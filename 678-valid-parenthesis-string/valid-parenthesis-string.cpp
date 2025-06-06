class Solution {
public:
    bool f(string s, int i, int count, vector<vector<int>> &dp){
        if(count<0) return false;
        if(i==s.size()) return count==0;

        if(dp[i][count]!=-1) return dp[i][count];

        if(s[i]=='(') return f(s,i+1,count+1,dp);
        if(s[i]==')') return f(s,i+1,count-1,dp);

        return dp[i][count]=f(s,i+1,count+1,dp) | f(s,i+1,count-1,dp) | f(s,i+1,count,dp);
    }
    // bool checkValidString(string s) {
    //     int mini=0; int maxi=0;
    //     for(int i=0;i<s.size();i++){
    //         if(s[i]=='('){
    //             mini++; maxi++;
    //         }
    //         else if(s[i]==')'){
    //             mini--; maxi--;
    //         }
    //         else{
    //             mini--; maxi++;
    //         }
    //         mini=max(mini,0);
    //         if(maxi<0) return false;
    //     }
    //     if(mini==0) return true;
    //     return false;
    // }

    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(s,0,0,dp);
    }
};