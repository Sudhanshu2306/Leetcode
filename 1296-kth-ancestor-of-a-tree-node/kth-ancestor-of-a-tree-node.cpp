class TreeAncestor {
public:
    vector<vector<int>> table;
    void fill(vector<int> &parent){
        int n=parent.size();
        table.resize(20,vector<int>(n,-1));
        for(int i=0;i<n;i++) table[0][i]=parent[i];

        for(int i=1;i<20;i++){
            for(int j=0;j<n;j++){
                if(table[i-1][j]==-1) table[i][j]=-1;
                else table[i][j]=table[i-1][table[i-1][j]];
            }
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        fill(parent);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<20;i++){
            if((1&(k>>i))==1) node=table[i][node];
            if(node==-1) break;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */