class DisjointSet{
    public:
    vector<int> size,parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int parent_u=findParent(u);
        int parent_v=findParent(v);

        if(parent_u==parent_v) return;
        if(size[parent_u]>size[parent_v]){
            parent[parent_v]=parent_u;
            size[parent_u]+=size[parent_v];
        }
        else{
            parent[parent_u]=parent_v;
            size[parent_v]+=size[parent_u];
        }
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);
        vector<int> ans;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            if(ds.findParent(u)!=ds.findParent(v)){
                ds.unionBySize(u,v);
            }
            else{
                ans=i; break;
            }
        }
        return ans;
    }
};