class Solution {
public:
    int diameter(map<int,vector<int>> &adj, int n){
        queue<int> q; q.push(0);
        vector<int> vis(n,0); vis[0]=1;
        int last;
        while(!q.empty()){
            int z=q.size();
            for(int i=0;i<z;i++){
                last=q.front(); q.pop();
                vis[last]=1;
                for(auto it:adj[last]){
                    if(!vis[it]) q.push(it);
                }
            }
        }
        q.push(last);
        vector<int> temp(n,0); temp[last]=1;
        int ans=0;
        while(!q.empty()){
            int z=q.size();
            for(int i=0;i<z;i++){
                int last=q.front(); q.pop();
                temp[last]=1;
                for(auto it:adj[last]){
                    if(!temp[it]) q.push(it);
                }
            }
            ans++;
        }
        return ans-1;
    }
    int ff(vector<vector<int>> &edges){
        if(edges.size()==0) return 0;
        map<int,vector<int>> adj;
        set<int> st;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            st.insert(it[0]); st.insert(it[1]);
        }
        return diameter(adj,st.size());
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int x=ff(edges1); int y=ff(edges2);
        return max({x,y,(x+1)/2+(y+1)/2+1});
    }
};