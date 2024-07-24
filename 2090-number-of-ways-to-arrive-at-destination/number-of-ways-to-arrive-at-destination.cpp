class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        vector<pair<long long,long long>> adj[n];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }

        const long long mod=1e9+7;
        vector<long long> dist(n,LONG_MAX), ways(n,0);
        dist[0]=0;
        ways[0]=1;
        // {dist,node}
        pq.push({0,0});

        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            long long d=x.first;
            long long node=x.second;

            if(dist[node]<d) continue;
            for(auto i:adj[node]){
                long long adjNode=i.first;
                long long edw=i.second;

                if(d+edw<dist[adjNode]){
                    dist[adjNode]=edw+d;
                    ways[adjNode]=ways[node];
                    pq.push({edw+d,adjNode});
                }
                else if(d+edw==dist[adjNode]) {
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;

    }
};