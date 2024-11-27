class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back({i+1,1});
        }
        int m=queries.size();
        vector<int> ans;

        for(auto i:queries){
            adj[i[0]].push_back({i[1],1});
            vector<int> dist(n,1e9);
            dist[0]=0;

            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            // {dist,node}
            pq.push({0,0}); 

            while(!pq.empty()){
                auto x=pq.top();
                pq.pop();
                int dd=x.first;
                int node=x.second;

                if(dd>dist[node]) continue;

                for (auto it:adj[node]) {
                    int v=it.first; int d=it.second;
                    if (dist[node]+d<dist[v]) {
                        dist[v]=dist[node]+d;
                        pq.push({dist[v],v});
                    }
                }
            }
            ans.push_back(dist[n-1]==1e9?-1:dist[n-1]);

        }
        return ans;
    }
};