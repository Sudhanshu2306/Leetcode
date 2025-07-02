class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int mini=1e9;
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0], v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            vector<int> dist(n,-1);
            vector<int> parent(n,-1);
            queue<int> q;
            q.push(i);
            dist[i]=0;
            while(!q.empty()){
                int node=q.front(); q.pop();
                
                for(auto it:adj[node]){
                    if(dist[it]==-1){
                        q.push(it);
                        dist[it]=dist[node]+1;
                        parent[it]=node;
                    }
                    else if(node!=parent[it] && parent[node]!=it){
                        mini=min(mini,dist[node]+dist[it]+1);
                    }
                }
            }
        }
        return mini==1e9?-1:mini;
    }
};