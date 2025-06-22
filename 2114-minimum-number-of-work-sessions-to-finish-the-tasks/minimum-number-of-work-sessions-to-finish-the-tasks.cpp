class Solution {
public:
    int dp[16][1<<14];
    int f(int mask, vector<int>&tasks, int time, int st){
        if(mask==0) return 0;

        if(dp[time][mask]!=-1) return dp[time][mask];

        int ans=1e9;
        for(int i=0;i<tasks.size();i++){
            if(mask&(1<<i)){
                if(time+tasks[i]<=st) ans=min(ans,f(mask^(1<<i),tasks,time+tasks[i],st));
                else ans=min(ans,1+f(mask^(1<<i),tasks,tasks[i],st));
            }
        }
        return dp[time][mask]=ans;
    }
    int minSessions(vector<int>& tasks, int st) {
        int n=tasks.size();
        memset(dp,-1,sizeof(dp));
        return 1+f((1<<n)-1,tasks,0,st);
    }
};