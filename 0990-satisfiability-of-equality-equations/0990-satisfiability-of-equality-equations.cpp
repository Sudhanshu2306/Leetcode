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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        for(auto i:equations){
            int x=i[0]-'a';
            int y=i[3]-'a';

            if(i[1]=='!') continue;
            ds.unionBySize(x,y);
        }

        for(auto i:equations){
            if(i[1]=='=') continue;
            int x=i[0]-'a';
            int y=i[3]-'a';
            if(ds.findParent(x)==ds.findParent(y)) return false;
        }
        return true;
    }
};