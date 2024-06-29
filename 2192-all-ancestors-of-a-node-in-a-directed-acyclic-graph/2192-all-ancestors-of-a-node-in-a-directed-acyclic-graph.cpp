class Solution {
public:
    void bfs(vector<vector<int>> &temp, vector<vector<int>> &ans, int n, int i){
        vector<int> vis(n,0);
        vis[i]=1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto it:temp[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                    ans[i].push_back(it);
                }
            }
        }
        sort(ans[i].begin(),ans[i].end());
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), temp(n);
        int m=edges.size();
        for(int i=0;i<m;i++){
            temp[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++){
            bfs(temp,ans,n,i);
        }
        return ans;
    }
};