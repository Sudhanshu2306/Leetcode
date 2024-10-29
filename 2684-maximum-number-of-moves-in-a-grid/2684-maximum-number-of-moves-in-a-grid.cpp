class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        queue<vector<int>> q;
        int r,c,maxi=0;//max value = 0
        for(int i=0;i<m;i++)
        {q.push({i,0,0});//row,column,lenght
         vis[i][0]=1;//marking as visited
        }
        while(!q.empty())//BFS
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            { 
                int r=q.front()[0];
                int c=q.front()[1];
                int cou=q.front()[2];
                q.pop();
                maxi=max(maxi,c);
                vector<int> r1={-1,0,1};//row values
                vector<int> c1={1,1,1};// column values
                for(int j=0;j<3;j++)
                {
                    int nr=r+r1[j],nc=c+c1[j];//calculation of new values
                    if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]>grid[r][c])
                    //checking if exists or not and visited or not and new value is greater then original 
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc,cou+1});
                    }
                }
            }
        }
        return maxi;

    }
};