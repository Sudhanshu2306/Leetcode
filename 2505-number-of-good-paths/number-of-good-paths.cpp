class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }

    void join(int u, int v){
        int parent_u=findParent(u), parent_v=findParent(v);

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
    vector<vector<int>> adj;
    int count=0;

    void dfs(vector<int> &vals, vector<int> &vis, int root, int curr) {
        if(root!=curr && vals[root]==vals[curr]) count++;
        vis[curr]=1;

        for(auto it:adj[curr]){
            if(!vis[it] && vals[it]<=vals[root]){
                dfs(vals,vis,root,it);
            }
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        adj.resize(n);
        
        for(auto &it:edges){
            int u=it[0], v=it[1];
            if(vals[u]>=vals[v]) adj[u].push_back(v);
            else adj[v].push_back(u);
        }
        DisjointSet dsu(n+1);
        // for(int i=0;i<n;i++){
        //     vector<int> vis(n,0);
        //     dfs(vals,vis,i,i);
        // }

        map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[vals[i]].push_back(i);
        int count=0;
        for(auto it:mp){
            auto nodes=it.second;
            for(auto u:nodes){
                for(auto it:adj[u]){
                    dsu.join(it,u);
                }
            }
            map<int,int> x;
            for(auto u:nodes){
                x[dsu.findParent(u)]++;
            }
            for(auto it:x){
                int y=it.second;
                count+=y*(y-1)/2;
            }
        }

        return count+n;
    }
};
