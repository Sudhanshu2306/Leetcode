class Solution {
public:
    vector<vector<int>> adj;
    long long ans=0;
    long long dfs(int node, int parent, vector<int> &cost){
        vector<long long> score_of_subtrees;
        for(auto it:adj[node]){
            if(it==parent) continue;
            long long x=dfs(it,node,cost);
            score_of_subtrees.push_back(x);
        }

        // case of leaf node
        if(score_of_subtrees.size()==0) return cost[node];

        long long max_score=*max_element(score_of_subtrees.begin(),score_of_subtrees.end());
        for(auto it:score_of_subtrees){
            if(it<max_score) ans++;
        }

        return max_score+cost[node];
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        adj.resize(n);
        for(auto it:edges){
            int u=it[0], v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,cost);
        return ans;
    }
};