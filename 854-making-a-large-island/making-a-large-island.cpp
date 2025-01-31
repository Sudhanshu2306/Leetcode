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
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;

                for(int k=0;k<4;k++){
                    int nr=i+dx[k];
                    int nc=j+dy[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int nodeEq=i*n+j;
                        int adjEq=nr*n+nc;
                        ds.unionBySize(nodeEq,adjEq);
                    }
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int dx[]={-1,0,1,0};
                int dy[]={0,1,0,-1};
                unordered_set<int> st;
                for(int k=0;k<4;k++){
                    int nr=i+dx[k];
                    int nc=j+dy[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        st.insert(ds.findParent(nr*n+nc));
                    }
                }
                int sizeTotal=1;
                for(auto it:st) sizeTotal+=ds.size[it];
                ans=max(ans,sizeTotal);
            }
        }
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findParent(i)]);
        }
        return ans;
    }
};