class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findParent(int node){
        if(node==parent[node]) return node;

        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int u, int v){
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
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        DisjointSet dsu(40002);
        int x=40001;
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    if(i==0 || i==n-1 || j==0 || j==m-1){
                        dsu.unionBySize(i*m+j,x);
                    }
                    else{
                        for(int k=0;k<4;k++){
                            int ni=i+dx[k], nj=j+dy[k];
                            if(ni>=0 && ni<n && nj>=0 && nj<m && board[ni][nj]=='O'){
                                dsu.unionBySize(i*m+j,ni*m+nj);
                            }
                        }
                    }
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    int u=dsu.findParent(i*m+j);
                    int v=dsu.findParent(x);

                    if(u!=v) board[i][j]='X';
                }
            }
        }
    }
};