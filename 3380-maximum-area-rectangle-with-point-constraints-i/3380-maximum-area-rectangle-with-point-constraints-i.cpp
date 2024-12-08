class Solution {
public:
bool ff(vector<int>& p, int x1, int y1, int x2, int y2) {
    return (p[0] >= x1 && p[0] <= x2 && p[1] >= y1 && p[1] <= y2);
}
    int maxRectangleArea(vector<vector<int>>& points) {
        int n=points.size();
        int maxi=-1;
        sort(points.begin(),points.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        int xmin=points[i][0];
                        int ymin=points[i][1];
                        int xmax=points[l][0];
                        int ymax=points[l][1];
                        if(points[j][0]!=xmin||points[j][1]!=ymax)break;
                        if(points[k][0]!=xmax||points[k][1]!=ymin)break;
                        bool f=0;
                        for(int m=i+1;m<=l;m++){
                            if(m==j||m==k||m==l)continue;
                            if(points[m][0]>=xmin&&points[m][0]<=xmax&&points[m][1]>=ymin&&points[m][1]<=ymax){
                                f=1;break;
                            }
                        }
                        if(f) break;
                        int rl=xmax-xmin,rb=ymax-ymin;
                        maxi=max(maxi,rl*rb);
                    }
                }
            }
            
        }
        return maxi;
    }
};