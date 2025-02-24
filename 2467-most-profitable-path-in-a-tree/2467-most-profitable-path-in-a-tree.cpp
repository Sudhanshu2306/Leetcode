class Solution {
public:
    int dfsForAlice(int node, int parent, int time, vector<vector<int>> &adj, vector<int> &amount, map<int,int> &mp){
        int ans=-1e9;
        for(auto it:adj[node]){
            if(it!=parent){
                ans=max(ans,dfsForAlice(it,node,time+1,adj,amount,mp));   
            }
        }
        if(ans==-1e9) ans=0;
        if(mp.find(node)==mp.end() || mp[node]>time) ans+=amount[node];
        else if(mp[node]==time) ans+=amount[node]/2;
        else ans+=0;
        
        return ans;
    }
    bool dfsForBob(int node, int time, vector<vector<int>> &adj, map<int,int> &mp){
        mp[node]=time;
        if(node==0) return true;

        for(auto it:adj[node]){
            if(mp.find(it)==mp.end() && dfsForBob(it,time+1,adj,mp)) return true;
        }
        mp.erase(node);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // there's one important thing, node bob to 0 is a unique path, as it is a tree ! 
        int time=0;
        int n=edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int,int> mp;
        dfsForBob(bob,0,adj,mp);

        int ans=dfsForAlice(0,-1,0,adj,amount,mp);
        return ans;
    }
};