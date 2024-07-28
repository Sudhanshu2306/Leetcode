class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n];
        for(auto edge:edges) {
            int u=edge[0], v=edge[1];
            // changing to zero based indexing
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // {time,node};
        pq.push({0,0});
        vector<int> dist(n,1e9);
        vector<int> dist_second(n,1e9);

        dist[0]=0;
        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            int t=x.first;
            int node=x.second;

            int wait_time=0;
            if((t/change)%2==1) wait_time+=(change-(t%change));
            t+=wait_time;

            for(auto i:adj[node]){
                int v=i;
                if(time+t<dist[v]){
                    dist_second[v]=dist[v];
                    dist[v]=time+t;
                    pq.push({dist[v],v});
                }
                // calculating second maximum time
                else if(time+t<dist_second[v] && (time+t)!=dist[v]){
                    dist_second[v]=time+t;
                    pq.push({time+t,v});
                }
            }
        }
        return dist_second[n-1];
    }
};