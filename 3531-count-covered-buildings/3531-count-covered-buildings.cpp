class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& a) {
        vector<int> minr(n+1,1e9),minc(n+1,1e9);
        vector<int> maxr(n+1,-1e9),maxc(n+1,-1e9);
        int count=0;
        for(auto it:a){
            int x=it[0],y=it[1];
            minr[y]=min(minr[y],x);
            maxr[y]=max(maxr[y],x);
            minc[x]=min(minc[x],y);
            maxc[x]=max(maxc[x],y);
        }
        for(auto it:a){
            int x=it[0],y=it[1];
            if(x>minr[y] && x<maxr[y] && y>minc[x] && y<maxc[x]) count++;
        }
        return count;
    }
};