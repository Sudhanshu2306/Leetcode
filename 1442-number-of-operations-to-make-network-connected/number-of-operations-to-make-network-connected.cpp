class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int parent_u=findParent(u);
        int parent_v=findParent(v);

        if(parent_u==parent_v) return;

        if(size[parent_u]>size[parent_v]){
            parent[parent_v]=parent_u;
            size[parent_u]+=size[parent_v];
        }else{
            parent[parent_u]=parent_v;
            size[parent_v]+=size[parent_u];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet x(n);
        int count=0;
        for(auto i:connections){
            int u=i[0];
            int v=i[1];
            if(x.findParent(u)==x.findParent(v)) count++;
            else{
                x.unionBySize(u,v);
            }
        }

        int componentCount=0;
        for(int i=0;i<n;i++){
            if(x.findParent(i)==i) componentCount++;
        }
        if(count>=componentCount-1) return componentCount-1;
        return -1;
    }
};