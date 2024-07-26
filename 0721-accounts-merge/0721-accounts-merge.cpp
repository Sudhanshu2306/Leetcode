class DisjointSet{
    public:
        vector<int> parent,size;

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        int n=accounts.size();
        DisjointSet ds(n);
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }

        vector<string> merge[n];
        for(auto i:mp){
            string mail=i.first;
            int node=ds.findParent(i.second);
            merge[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merge[i].size()==0) continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};