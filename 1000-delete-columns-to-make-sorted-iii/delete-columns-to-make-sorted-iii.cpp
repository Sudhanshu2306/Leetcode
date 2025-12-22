class Solution {
public:
    int f(int k, int j, vector<string> &strs){
        for(int i=0;i<strs.size();i++){
            if(strs[i][k]>strs[i][j]) return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        vector<int> dp(m);

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                if(f(j,i,strs)){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return m-ans-1;
    }
};