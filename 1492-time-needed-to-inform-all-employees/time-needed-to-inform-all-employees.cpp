class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }

        queue<int> q;
        q.push(headID);

        vector<int> dist(n+1,0);
        int time=0;
        while(!q.empty()){
            int u=q.front(); q.pop();

            for(auto i:adj[u]){
                dist[i]=dist[u]+informTime[manager[i]];
                time=max(time,dist[i]);
                q.push(i);
                
            }
        }
        return time;

    }
};