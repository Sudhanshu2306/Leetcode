class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,1e9);
        dp[0]=0;
        for(int i=1;i<366;i++){
            if(find(days.begin(),days.end(),i)==days.end()) {dp[i]=dp[i-1]; continue;}
            for(int j=0;j<3;j++){
                if(j==0) dp[i]=min(dp[i],dp[max(0,i-1)]+costs[j]);
                if(j==1) dp[i]=min(dp[i],dp[max(0,i-7)]+costs[j]);
                if(j==2) dp[i]=min(dp[i],dp[max(0,i-30)]+costs[j]);
            }
        }
        return dp[365];
    }
};