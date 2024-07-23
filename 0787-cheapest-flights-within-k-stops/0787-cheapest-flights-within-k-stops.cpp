class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> q;
        // int n=flights.size();
        vector<pair<int,int>> adj[n];

        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        // {stops,{node,dist}};
        q.push({0,{src,0}});

        vector<int> c(n,1e9);
        c[src]=0;
        while(!q.empty()){
            auto i=q.front(); q.pop();
            int stops=i.first;
            int node=i.second.first;
            int dist=i.second.second;
            if(stops>k) continue;

            for(auto itr:adj[node]){
                int adjNode=itr.first;
                int d=itr.second;

                if(dist+d<c[adjNode] && stops<=k){
                    c[adjNode]=dist+d;
                    q.push({stops+1,{adjNode,c[adjNode]}});
                }
            }
        }
        if(c[dst]==1e9) return -1;
        return c[dst];
    }
};