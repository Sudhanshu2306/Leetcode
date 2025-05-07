class Solution {
public:
    int dfs(int root, int parent, vector<vector<int>> &adj, vector<int> &values){
        if(adj[root].size()==1 && root!=0) return values[root];
        long long sum=0;
        for(auto it:adj[root]){
            if(it!=parent){
                sum+=dfs(it,root,adj,values);
            }
        }
        return min(sum,1LL*values[root]);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0], v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans=accumulate(values.begin(),values.end(),0LL);
        long long x=dfs(0,-1,adj,values);
        return ans-x;
    }
};