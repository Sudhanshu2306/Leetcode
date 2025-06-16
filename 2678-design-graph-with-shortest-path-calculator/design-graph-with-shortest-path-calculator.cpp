class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int n=adj.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        pq.push({0,node1});
        dist[node1]=0;
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            int d=it.first, node=it.second;

            for(auto itr:adj[node]){
                int adjNode=itr.first, wt=itr.second;
                if(dist[adjNode]>dist[node]+wt){
                    dist[adjNode]=dist[node]+wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist[node2]==INT_MAX?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */