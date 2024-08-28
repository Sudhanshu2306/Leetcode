class DisjointSet{
    public:
    vector<int> parent,size;
    int count;
    DisjointSet(int n){
        count=0;
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int findparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findparent(parent[node]);
    }
    void unionBySize(int u,int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv) return;

        if(size[pv]>size[pu]){
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
        else{
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        count++;
    }
};

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r=grid1.size(), c=grid1[0].size();
        DisjointSet dsu(r*c+1); 
        int island=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int curr=i*c+j, down=(i+1)*c+j, right=i*c+(j+1);
                bool g2=grid2[i][j]==1;
                island+=g2;
                if(g2){
                    if(i+1<r && grid2[i+1][j]) dsu.unionBySize(curr, down);
                    if(grid1[i][j]==0) dsu.unionBySize(curr, r*c);

                    if(j+1<c && grid2[i][j+1]) dsu.unionBySize(curr, right);
                }
                
            }
        }
        return island-dsu.count;
    }
};