class Solution {
public:
    // return the size of subtree everytime
    int dfs(int node, int parent, vector<int> adj[], int &ans) {
        unordered_map<int,int> mp; 
        int size=1; 

        for(int it:adj[node]){
            // if child==parent, do nothing, as we do not want to go back again
            if(it==parent) continue;
            int cSize=dfs(it,node,adj,ans);
            mp[cSize]++;
            size+=cSize;
        }
        // temp[node]=size;
        if(mp.size()<=1) ans++;
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> adj[n];
        int ans=0;

        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // vector<int> temp(n,0);
        // starting parent is -1
        // int x=dfs(0,-1,adj,temp,ans);
        dfs(0,-1,adj,ans);
        // cout<<x<<endl;
        return ans;
    }
};