class Solution {
public:
    
    void dfs(int i, int j, int ic, int nc, vector<vector<int>> &image){
        int n=image.size();
        int m=image[0].size();
        if(i<0 || j<0)
            return;
        if(i>=n || j>=m)
            return;
        if(image[i][j]!=ic)
            return;
        
        image[i][j]=nc;
        dfs(i,j-1,ic,nc,image);
        dfs(i,j+1,ic,nc,image);
        dfs(i+1,j,ic,nc,image);
        dfs(i-1,j,ic,nc,image);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]!=color)
            dfs(sr,sc,image[sr][sc],color,image);
        return image;
    }
};