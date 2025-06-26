class Solution {
public:
    vector<vector<int>> a,b;
    set<vector<int>> ans;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void dfs(vector<vector<int>> &mat, int r, int c, vector<vector<int>> &vis){
        vis[r][c]=1;
        if(a[r][c] && b[r][c]) ans.insert({r,c});
        for(int i=0;i<4;i++){
            int nr=r+dx[i], nc=c+dy[i];
            if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() && !vis[nr][nc] && mat[r][c]<=mat[nr][nc]){
                dfs(mat,nr,nc,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();

        a.resize(n,vector<int>(m,0)); b.resize(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            dfs(mat,i,0,a);
            dfs(mat,i,m-1,b);
        }
        for(int i=0;i<m;i++){
            dfs(mat,0,i,a);
            dfs(mat,n-1,i,b);
        }
        vector<vector<int>> res(ans.begin(),ans.end());

        return res;
    }
};