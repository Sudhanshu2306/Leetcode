typedef long long ll;
class Solution {
public:
    ll mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> adj(n);
        for(auto it:roads){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({0,0}); // {dist,node}
        vector<ll> dist(n,1e18);
        vector<ll> dp(n,0);

        dp[0]=1; dist[0]=0;
        while(!pq.empty()){
            auto temp=pq.top(); pq.pop();
            ll d=temp.first, node=temp.second;

            if(d>dist[node]) continue;

            for(auto it:adj[node]){
                ll adjnode=it.first, w=it.second;

                if(d+w<dist[adjnode]){
                    pq.push({d+w,adjnode});
                    dist[adjnode]=d+w;
                    dp[adjnode]=dp[node]%mod;
                }
                else if(d+w==dist[adjnode]){
                    dp[adjnode]=(dp[node]+dp[adjnode])%mod;
                }
            }
        }
        return dp[n-1]%mod;
    }
};