class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    bool f(int n, int k, int mid, vector<int> &vis){
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(mid,i,vis);
            }
        }
        return count>=k;
    }
    void dfs(int mid, int node, vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first] &&  it.second>mid) dfs(mid,it.first,vis);
        }
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        adj.resize(n+1);
        int s=0, e=0;
        for(auto it:edges){
            int u=it[0], v=it[1], w=it[2];
            e=max(e,w);
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        while(s<=e){
            int mid=s+(e-s)/2;
            vector<int> vis(n+1,0);
            if(f(n,k,mid,vis)) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};