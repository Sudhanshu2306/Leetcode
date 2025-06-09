class Solution {
public:
    void dfs(int node, vector<int> &edges, vector<int> &vis, vector<int> &x, int &maxi, int curr){
        if(!vis[node]){
            vis[node]=1;
            x[node]=curr;
            if(edges[node]!=-1) dfs(edges[node],edges,vis,x,maxi,curr+1);
            x[node]=-1;
        }
        else{
            if(x[node]!=-1){
                maxi=max(maxi,curr-x[node]);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> vis(n+1,0);
        vector<int> x(n,-1);
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,edges,vis,x,maxi,0);
        }
        return maxi;
    }
};