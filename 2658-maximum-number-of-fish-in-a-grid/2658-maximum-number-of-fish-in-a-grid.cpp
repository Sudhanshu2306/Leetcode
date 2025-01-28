class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    int dfs(vector<vector<int>> &a, int r, int c){
        if(r<0 || c<0 || r>=a.size() || c>=a[0].size() || a[r][c]==0) return 0;

        int ans=a[r][c];
        a[r][c]=0;
        for(int i=0;i<4;i++){
            int nr=r+dx[i], nc=c+dy[i];
            ans+=dfs(a,nr,nc);
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& a) {
        int maxi=0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                if(a[i][j]>0) maxi=max(maxi,dfs(a,i,j));
            }
        }
        return maxi;
    }
};