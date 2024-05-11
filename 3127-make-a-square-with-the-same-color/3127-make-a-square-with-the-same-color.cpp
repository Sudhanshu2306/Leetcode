class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n=grid.size();
        int w,b;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                w=0,b=0;
                grid[i][j]=='B'?b++:w++;
                grid[i][j+1]=='B'?b++:w++;
                grid[i+1][j]=='B'?b++:w++;
                grid[i+1][j+1]=='B'?b++:w++;

                if(b>=3 || w>=3) return true;
            }
        }

        return false;
    }
};