class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        size.resize(n+1,1);
    }

    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int x=findParent(u);
        int y=findParent(v);

        if(x==y) return;
        if(size[x]>=size[y]){
            parent[y]=parent[x];
            size[x]+=size[y];
        }
        else{
            parent[x]=parent[y];
            size[y]+=size[x];
        }
    }
};

class Solution {
public:
    int maximumInvitations(vector<int>& a) {
        int n=a.size();
        DisjointSet dsu(n);

        vector<int> in(n+1), ans(n+1,1);
        for(int i=0;i<n;i++) in[a[i]]++;

        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }

        while(!q.empty()){
            auto x=q.front(); q.pop();
            int y=a[x];
            ans[y]=max(ans[y],ans[x]+1);
            in[y]--;
            if(in[y]==0) q.push(y);
        }
        for(int i=0;i<=n;i++){
            if(in[i]>0){
                dsu.unionBySize(i,a[i]);
            }
        }

        int maxi=0;
        int total=0;
        for(int i=0;i<=n;i++){
            if(in[i]==0) continue;
            int singleSize=dsu.size[dsu.findParent(i)];
            if(singleSize==2){
                int v=a[i];
                in[v]--;
                singleSize=ans[i]+ans[v];
                total+=singleSize;
            }
            else maxi=max(maxi,singleSize);
        }
        return max(maxi,total);
    }
};