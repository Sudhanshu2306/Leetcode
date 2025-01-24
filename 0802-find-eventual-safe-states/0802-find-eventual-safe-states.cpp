class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
            }
        }

        vector<int> in(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                in[i]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }

        while(!q.empty()){
            int x=q.front(); q.pop();
            topo.push_back(x);

            for(auto it:adj[x]){
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;

    }
};