class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<vector<int>> nw;
    void dfs(int node, vector<int> &vis, int mid){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first] &&  it.second<=mid) dfs(it.first,vis,mid);
        }
    }
    bool f(int mid, int k){
        int n=adj.size();
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                if(count>k)return false;
                dfs(i,vis,mid);
            }
        }
        return true;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        adj.resize(n);
        int s=0, e=0;
        for(auto it:edges){
            int u=it[0], v=it[1], w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            e=max(e,w);
        }
        while(s<=e){
            int mid=s+(e-s)/2;
            if(f(mid,k)) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};