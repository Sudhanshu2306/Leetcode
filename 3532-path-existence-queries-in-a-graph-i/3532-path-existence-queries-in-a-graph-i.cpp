class DisjointSet{
    public:
    vector<int> size,parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int parent_u=findParent(u), parent_v=findParent(v);
        if(parent_u==parent_v) return;

        if(size[parent_u]>size[parent_v]){
            size[parent_u]+=size[parent_v];
            parent[parent_v]=parent_u;
        }
        else{
            size[parent_v]+=size[parent_u];
            parent[parent_u]=parent_v;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet dsu(1e5+1);
        for(int i=0;i<nums.size()-1;i++){
            int u=i,v=i+1;
            int nu=nums[u],nv=nums[v];

            if (nv-nu<=maxDiff) dsu.unionBySize(u,v);
        }
        vector<bool> ans;
        for(auto it:queries){
            int x=it[0],y=it[1];
            int px=dsu.findParent(x),py=dsu.findParent(y);
            if(px==py) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};