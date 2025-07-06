class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int,int,int>>> adj(n);

        for(auto it:edges){
            int u=it[0], v=it[1], s=it[2], e=it[3];
            adj[u].push_back({v,s,e});
        }
        queue<pair<int,int>> q;
        vector<int> time(n,INT_MAX);
        time[0]=0;
        q.push({0,0});
        while(!q.empty()){
            auto it=q.front(); q.pop();
            int node=it.first, t=it.second;

            for(auto [v,s,e]:adj[node]){
                int next=max(t,s);
                if(next+1<time[v] && next<=e){
                    time[v]=next+1;
                    q.push({v,next+1});
                }
            }
        }
        return time[n-1]==INT_MAX?-1:time[n-1];
    }
};