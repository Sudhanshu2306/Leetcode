class Solution {
public:
    void dfs(vector<int> &edges, int node, vector<int> &a, vector<int> &vis){
        vis[node]=1;
        if(edges[node]!=-1 && !vis[edges[node]]){
            a[edges[node]]=a[node]+1;
            dfs(edges,edges[node],a,vis);
        } 
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> x(n,0),y(n,0);
        vector<int> vis(n,0), vis1(n,0);
        dfs(edges,node1,x,vis);        
        dfs(edges,node2,y,vis1);
        int mini=1e9, ans=-1;
        for(int i=0;i<n;i++){
            if(vis[i]==1 && vis1[i]==1 && mini>max(x[i],y[i])){
                mini=max(x[i],y[i]); ans=i;
            }
        }
        return ans;
    }
};