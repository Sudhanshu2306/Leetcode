class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<vector<int>>& stones){
        int n=stones.size();
        vis[i]=1;
        for(int j=0;j<n;j++){
            if(vis[j]==0){
                if(stones[i][0]==stones[j][0]) dfs(j,vis,stones);
                if(stones[i][1]==stones[j][1]) dfs(j,vis,stones);
            }
        } return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        
        vector<int> vis(n);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0) {
                dfs(i,vis,stones);
                count++;
            }
        }
        return n-count;
    }
};