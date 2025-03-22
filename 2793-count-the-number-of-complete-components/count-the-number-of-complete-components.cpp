class Solution {
public:
    void dfs(vector<vector<int>> &adj, int node, int &count, int &edges, vector<int> &vis){
        vis[node]=1;
        count++; edges+=adj[node].size();
        for(auto it:adj[node]){
            if(!vis[it]) dfs(adj,it,count,edges,vis);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++){
            int count=0, edges=0;
            if(!vis[i]){
                dfs(adj,i,count,edges,vis);
                if(count*(count-1)==edges) ans++;
            }
        }
        return ans;
    }
};