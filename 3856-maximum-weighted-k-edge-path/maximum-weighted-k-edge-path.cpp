class Solution {
public:
    string f(int node, int steps, int wt) {
        return to_string(node)+","+to_string(steps)+","+to_string(wt);
    }
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<tuple<int,int,int>> q;
        // {node,num_edges,total_wt}
        set<string> vis;
        for(int i=0;i<n;i++){
            vis.insert(f(i,0,0));
            q.push({i,0,0});
        }
        int maxi=-1;
        while(!q.empty()){
            auto [node,num,wt]=q.front(); q.pop();
            if(num==k) maxi=max(maxi,wt);

            for(auto it:adj[node]){
                if(wt+it.second<t && vis.find(f(it.first,num+1,wt+it.second))==vis.end()){
                    q.push({it.first,num+1,wt+it.second});
                    vis.insert(f(it.first,num+1,wt+it.second));
                }
            }
        }
        return maxi;
    }
};