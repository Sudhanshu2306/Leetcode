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
        int parent_u=findParent(u);
        int parent_v=findParent(v);
        if(parent_u==parent_v) return;
        else if(parent_u<parent_v){
            parent[parent_v]=parent_u;
        }
        else{
            parent[parent_u]=parent_v;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        DisjointSet dsu(26);

        for(int i=0;i<n;i++){
            dsu.unionBySize(s1[i]-'a',s2[i]-'a');
        }
        string ans="";
        for(auto it:baseStr){
            char ch='a'+dsu.findParent(it-'a');
            ans+=ch;
        }
        return ans;
    }
};