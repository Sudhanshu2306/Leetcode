class Solution {
public:
    int dfs(int mid, vector<int> &vis, vector<vector<pair<int,int>>> &adj, int node){
        vis[node]=1;
        int count=1;

        for(auto it:adj[node]){
            if(!vis[it.first] && it.second<=mid){
                count+=dfs(mid,vis,adj,it.first);
            }
        }
        return count;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            adj[it[1]].push_back({it[0],it[2]});
        }
        int s=1,e=1e8;
        while(s<=e){
            int mid=s+(e-s)/2;
            vector<int> vis(n,0);
            if(dfs(mid,vis,adj,0)==n){
                e=mid-1;
            }
            else s=mid+1;
        }
        return s>=1e8?-1:s;
    }
};