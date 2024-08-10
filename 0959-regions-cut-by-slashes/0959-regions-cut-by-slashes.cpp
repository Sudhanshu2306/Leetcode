class DisjointSet{
    public:
    vector<int> parent,size;
    int count=1;
    DisjointSet(int n){
        parent.resize(n+1,1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int parent_u=findParent(u);
        int parent_v=findParent(v);
        if(parent_u==parent_v){
            count++;
            return;
        }
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
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        int val=(n+1)*(n+1)+1;
        DisjointSet ds(val);

        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0 || i==n || j==n){
                    int cell=i*(n+1)+j;
                    if(cell!=0) ds.unionBySize(0,cell);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    int point1=i*(n+1)+(j+1);
                    int point2=(i+1)*(n+1)+j;
                    ds.unionBySize(point1,point2);
                }
                else if(grid[i][j]=='\\'){
                    int point1=i*(n+1)+j;
                    int point2=(i+1)*(n+1)+(j+1);
                    ds.unionBySize(point1,point2);
                }
            }
        }
        return ds.count;
    }
};