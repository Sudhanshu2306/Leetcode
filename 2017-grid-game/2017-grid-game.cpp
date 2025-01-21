class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long> p1(n),p2(n);
        p1[0]=grid[0][0]; p2[0]=grid[1][0];
        for(int i=1;i<n;i++){
            p1[i]=p1[i-1]+grid[0][i];
            p2[i]=p2[i-1]+grid[1][i];
        }
        
        long long mini=1e18;
        for(int i=0;i<n;i++){
            long long x=p1[n-1]-p1[i];
            long long y;
            if(i==0) y=0;
            else y=p2[i-1];
            mini=min(mini,max(x,y));
        }
        return mini;
    }
};