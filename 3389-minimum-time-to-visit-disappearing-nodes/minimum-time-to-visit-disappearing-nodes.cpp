class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>> adj[n];
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }

        // treat time as distance! kyu? kyuki kya fark padta h distance lo ya time, distance
        // bolne se shortest path dimag mein aa jata h isiliye

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,1e9);

        dist[0]=0;
        pq.push({0,0});
        
        vector<int> vis(n,0);
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(vis[node]==1) continue;
            if(dis>=disappear[node]) continue;
            vis[node]=1;
            for(auto i:adj[node]){
                int v=i.first;
                int wt=i.second;
                if(dis+wt<dist[v] && dis+wt<disappear[v]){
                    dist[v]=dis+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==1e9)dist[i]=-1;
        }
        return dist;
    }
};