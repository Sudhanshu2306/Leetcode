class Solution {
public: 
    vector<vector<int>> adj;
    map<int,set<int>> mp;
    vector<int> x;
    vector<int> vis;
    void dfs(int node, int cons){
        vis[node]=1;
        mp[cons].insert(node);
        x[node]=cons;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,cons);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        adj.resize(c+1);
        for(auto it:connections){
            int u=it[0], v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis.resize(c+1,0);
        x.resize(c+1);

        for(int i=1;i<=c;i++){
            if(!vis[i]){
                dfs(i,i);
            }
        }
        vector<int> ans;
        for(auto it:queries){
            int type=it[0]; int z=it[1];
            if(type==1){
                if(mp[x[z]].find(z)!=mp[x[z]].end()) ans.push_back(z);
                else if(mp[x[z]].size()!=0){
                    ans.push_back(*mp[x[z]].begin());
                } 
                else ans.push_back(-1);
            }
            else{
                if(mp[x[z]].find(z)!=mp[x[z]].end()) mp[x[z]].erase(z);
            }
        }
        return ans;
    }
};