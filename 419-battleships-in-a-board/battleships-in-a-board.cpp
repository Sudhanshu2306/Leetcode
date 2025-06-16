class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size(), cnt=0;
        if(m==0 || n==0) return cnt;
        
        for(int r=0;r<n;r++)
            for(int c=0;c<m;c++)
                cnt+=board[r][c]=='X' && (r==0 || board[r-1][c]!='X') && (c==0 || board[r][c-1]!='X');
        
        return cnt;
    }
};