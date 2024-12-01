class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>> &adj, int k){
        if(k<0) return 0;
        if(k==0) return 1;
        int ans=1;
        for(auto it:adj[node]){
            if(it==parent) continue;
            ans+=dfs(it,node,adj,k-1);
        }
        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1; int m=edges2.size()+1;
        vector<vector<int>> adj1(n),adj2(m);

        for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        int maxi=0;
        for(int i=0;i<m;i++){
            maxi=max(maxi,dfs(i,-1,adj2,k-1));
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(maxi+dfs(i,-1,adj1,k));
        }
        return ans;
    }
};