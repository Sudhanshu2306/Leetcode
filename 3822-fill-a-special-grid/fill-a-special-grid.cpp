class Solution {
public:
    void solve(vector<vector<int>> &a, int x, int y, int n, int k){
        if(n==0){
            a[x][y]=k; return;
        }
        int len=pow(2,n-1);
        int t=len*len;
        solve(a,x,y,n-1,k+3*t);
        solve(a,x,y+len,n-1,k);
        solve(a,x+len,y,n-1,k+2*t);
        solve(a,x+len,y+len,n-1,k+t);
    }
    vector<vector<int>> specialGrid(int n) {
        int x=pow(2,n);
        vector<vector<int>> ans(x,vector<int>(x));
        solve(ans,0,0,n,0);
        return ans;
    }
};