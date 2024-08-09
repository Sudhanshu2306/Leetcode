class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j){
        vector<int> temp;
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                temp.push_back(grid[i+r][j+c]);
            }
        }
        sort(temp.begin(),temp.end());
        if(temp!=vector<int>({1,2,3,4,5,6,7,8,9})) return false;
        int sum=grid[i][j]+grid[i+1][j]+grid[i+2][j];

        // column
        for(int c=0;c<3;c++){
            if((grid[i][j+c]+grid[i+1][j+c]+grid[i+2][j+c])!=sum) return false;
        }
        // row
        for(int r=0;r<3;r++){
            if((grid[i+r][j]+grid[i+r][j+1]+grid[i+r][j+2])!=sum) return false;
        }
        // diagonal
        if((grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2])!=sum) return false;
        if((grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2])!=sum) return false;

        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size(); int m=grid[0].size();
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                if(check(grid,i,j)) count++;
            }
        }
        return count;
    }
};