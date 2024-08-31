class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& p, int s, int e) {
        vector<pair<int,double>> adj[n];
        int j=0;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],p[j]});
            adj[i[1]].push_back({i[0],p[j]});
            j++;
        }
        priority_queue<pair<double,int>, vector<pair<double,int>>> pq; //max_heap
        vector<double> dist(n,-1);
        dist[s]=1.0;
        pq.push({1.0,s});
        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            int node=x.second;
            double wt=x.first;

            for(auto i:adj[node]){
                int v=i.first;
                double w=i.second;
                if(wt*w>dist[v]){
                    dist[v]=wt*w;
                    pq.push({dist[v],v});
                }
            }
        }
        if(dist[e]!=-1) return dist[e];
        else return (double)0;
    }
};