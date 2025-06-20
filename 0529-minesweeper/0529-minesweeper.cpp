class Solution {
public:
    vector<vector<int>> vis;
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={1,0,-1,1,-1,-1,1,0};
    void dfs(vector<vector<char>> &a, int r, int c){
        vis[r][c]=1;
        if(a[r][c]=='M'){
            a[r][c]='X'; return;
        }
        if(a[r][c]=='E'){
            bool flag=true;
            int count=0;
            for(int i=0;i<8;i++){
                int nr=r+dx[i], nc=c+dy[i];
                if(nr>=0 && nr<a.size() && nc>=0 && nc<a[0].size() && a[nr][nc]=='M'){
                    flag=false; count++;
                }
            }
            if(flag){
                a[r][c]='B';
                for(int i=0;i<8;i++){
                    int nr=r+dx[i], nc=c+dy[i];
                    if(nr>=0 && nr<a.size() && nc>=0 && nc<a[0].size() && vis[nr][nc]!=1){
                        dfs(a,nr,nc);
                    }
                }
            }
            else{
                a[r][c]=count+'0'; return;
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n=board.size(), m=board[0].size();
        vis.resize(n,vector<int>(m,0));
        dfs(board,click[0],click[1]);
        return board;
    }
};