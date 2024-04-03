class Solution {
public:
    bool f(vector<vector<char>>& board, string word, int i, int  j, int ind){
        if(ind>=word.size()) return 1;

        char ch=board[i][j];

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[ind])
            return false;

        board[i][j]='#';

        bool left=f(board,word,i,j-1,ind+1);
        bool left=f(board,word,i,j-1,ind+1);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]) 
                    if(f(board,word,i,j,0)) 
                        return true;
            }
        }
        return false;
    }
};