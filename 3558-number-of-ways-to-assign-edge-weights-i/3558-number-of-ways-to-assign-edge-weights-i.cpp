class Solution {
public:
    int mod=1e9+7;
    vector<int> vis;
    int dfs(int root, vector<vector<int>> &adj){
        vis[root]=1;
        int d=0;
        for(auto it:adj[root]){
            if(!vis[it] && it!=root){
                d=max(d,dfs(it,adj));
            }
        }
        return 1+d;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vis.resize(n+1,0);
        vector<vector<int>> adj(n+1);
        for(auto it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxi=dfs(1,adj);
        int res=1;
        for(int i=1;i<maxi-1;i++)
            res=(long long)res*2%mod;
            return res;
    }
};