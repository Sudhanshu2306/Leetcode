class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<vector<int>> adj(n);
        for(auto it:a){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> in(n,0);
        for(auto it:a){
            in[it[0]]++;
        }
        queue<int> q; 
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int x=q.front(); q.pop();
            count++;
            for(auto it:adj[x]){
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        return count==n;
    }
};