class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<vector<int>> adj(n+1);

        for(auto it:edges){
            int u=it[0], v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> deg(n+1,0);
        for(int i=0;i<n;i++){
            deg[i]=adj[i].size();
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==1) q.push(i);
        }
        int rem=n;
        queue<int> leafwithcoins;
        while(!q.empty()){
            auto node=q.front(); q.pop();
            if(coins[node]==1){
                leafwithcoins.push(node);
                continue;
            } 
            rem--;
            for(auto it:adj[node]){
                auto itptr=find(adj[node].begin(),adj[node].end(),it);
                auto nodeptr=find(adj[it].begin(),adj[it].end(),node);
                adj[it].erase(nodeptr);
                adj[node].erase(itptr);

                if(adj[it].size()==1) q.push(it);
            }
        }

        for(int i=0;i<2;i++){
            int y=leafwithcoins.size();
            while(y--){
                auto node=leafwithcoins.front(); leafwithcoins.pop();

                rem--;

                for(auto it:adj[node]){
                    auto itptr=find(adj[node].begin(),adj[node].end(),it);
                    auto nodeptr=find(adj[it].begin(),adj[it].end(),node);
                    adj[it].erase(nodeptr);
                    adj[node].erase(itptr);

                    if(adj[it].size()==1) leafwithcoins.push(it);
                }
            }
        }
        
        return rem?(rem-1)*2:0;
    }
};