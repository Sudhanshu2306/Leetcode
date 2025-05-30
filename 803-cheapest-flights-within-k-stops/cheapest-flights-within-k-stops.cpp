class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<tuple<int,int,int>> q;
        q.push({0,src,0});

        while(!q.empty()){
            auto [stops,node,d]=q.front(); q.pop();

            if(stops>k) continue;

            for(auto it:adj[node]){
                if(d+it.second<dist[it.first]){
                    dist[it.first]=d+it.second;
                    q.push({stops+1,it.first,dist[it.first]});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};