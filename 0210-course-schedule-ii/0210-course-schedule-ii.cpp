class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<vector<int>> adj(n);
        for(auto it:a){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> in(n,0);
        queue<int> q;
        for(auto it:a) in[it[0]]++;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int x=q.front(); q.pop();
            topo.push_back(x);

            for(auto it:adj[x]){
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        if(topo.size()==n) return topo;
        return {}; 
    }
};