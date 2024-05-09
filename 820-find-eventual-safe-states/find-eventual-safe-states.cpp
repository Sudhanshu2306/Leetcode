class Solution {
public:

    bool dfs(int i,vector<vector<int>> &adj,vector<int> &vis,vector<int> &visPath,vector<int> &dp){
        if(dp[i] == 1){
            return false;
        }
        vis[i] = 1;
        visPath[i] = 1;
        dp[i] = 0;
        for(auto it : adj[i]){
            if(!vis[it]){
                if(dfs(it,adj,vis,visPath,dp)){
                    dp[i] = 0;
                    return true;
                }
            }
            else if(visPath[it]){
                dp[i] = 0;
                return true;
            }
        }
        visPath[i] = 0;
        dp[i] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>dp(n);
        vector<int>vis(n);
        vector<int>visPath(n);
        for(int i = 0;i < n;i++){
            if(vis[i] == 0){
                dfs(i,graph,vis,visPath,dp);
            }
        }
        vector<int>ans;
        for(int i = 0;i < n;i++){
            if(dp[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};