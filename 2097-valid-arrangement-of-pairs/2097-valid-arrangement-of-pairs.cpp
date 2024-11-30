class Solution {
public:
    map<int,vector<pair<int,int>>> adj;
    vector<vector<int>> ans;

    void dfs(int node, vector<bool> &vis, vector<vector<int>> &pairs){
        while(!adj[node].empty()){
            auto x=adj[node].back(); adj[node].pop_back();
            if(!vis[x.second]){
                vis[x.second]=true;
                dfs(x.first,vis,pairs);
                ans.push_back(pairs[x.second]);
            }
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n=pairs.size();
        map<int,int> indegree,outdegree;
        for(int i=0;i<n;i++){
            int s=pairs[i][0]; int e=pairs[i][1];
            adj[s].push_back({e,i});
            outdegree[s]++; indegree[e]++;
        }

        int start=pairs[0][0];
        for(auto it:pairs){
            if(outdegree[it[0]]>indegree[it[0]]){
                start=it[0]; break;
            } 
        }

        vector<bool> vis(n,0);
        dfs(start,vis,pairs);

        return vector<vector<int>>(ans.rbegin(),ans.rend());
    }
};