class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        function<bool(int,int)> dfs=[&](int node, int x)->bool{
            vis[node]=x;
            for(auto it:graph[node]){
                if(vis[it]==-1){
                    if(!dfs(it,x^1)) return false;
                }
                else if(vis[it]==vis[node]) return false;
            }
            return true;
        };
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(i,0)) return false;
            }
        }
        return true;
    }
};