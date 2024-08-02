class Solution {
public:
    int dfs(int node, vector<int> adj[], unordered_map<int,int> &mp, int &loopNode){
        if(mp.find(node)!=mp.end()){
            loopNode=node;
            return mp[node];
        }
        
        mp[node]=0; // we do not enter any value but mark it zero so to mark this is present
        int count=1;

        for(auto i:adj[node]){
            count+=dfs(i,adj,mp,loopNode);
        }
        mp[node]=count;
        if(loopNode==node){
            node=adj[node][0];
            while(node!=loopNode){
                mp[node]=count;
                node=adj[node][0];
            }
        }
        return count;
    }

    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        vector<int> adj[n];

        for(int i=0;i<n;i++){
            adj[i].push_back(edges[i]);
        }

        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            if(mp.find(i)!=mp.end()){
                ans.push_back(mp[i]); continue;
            }
            else{
                int loopNode=-1;
                int count=dfs(i,adj,mp,loopNode);
                ans.push_back(count);
            }
        }
        return ans;
    }
};