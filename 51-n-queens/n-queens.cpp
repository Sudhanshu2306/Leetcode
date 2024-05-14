class Solution {
public:
    
    bool isSafe(int row, int col, vector<string> mat, int n){
        int x=row;
        int y=col;
        
        // three checks! why? kyuki we are moving from left to right, toh upar, niche, 
        // right and right diagonals koi kaam hi nahi h, kyuki aage abtak queen placed hi nahi h
        while(row>=0 && col>=0){
            // left upper diagonal
            if(mat[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=x;
        col=y;

        while(col>=0){
            // left check
            if(mat[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=x;
        col=y;

        while(row<n && col>=0){
            // left lower diagonal
            if(mat[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int col, vector<string> &mat, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(mat);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,mat,n)){
                mat[row][col]='Q';
                solve(col+1,mat,ans,n);
            }
            mat[row][col]='.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> mat(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            mat[i]=s;
        }
        solve(0,mat,ans,n);
        return ans;
    }
};