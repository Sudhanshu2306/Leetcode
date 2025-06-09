class Solution {
public:
    // int count=0;
    void dfs(vector<vector<int>> &adj, int node, vector<int> &vis, int &count){
        vis[node]=1;
        count++;
        for(auto it:adj[node]){
            if(it==node) continue;
            else{
                if(!vis[it]){
                    dfs(adj,it,vis,count);
                }
            } 
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0], v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        for(auto it:restricted) vis[it]=1;
        int count=0;
        dfs(adj,0,vis,count);
        return count;
    }
};