typedef long long ll;
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int count=0;
        sort(points.begin(),points.end());
        int x1=points[0][0];
        for(int i=1;i<points.size();i++){
            if(points[i][0]-x1>w){
                x1=points[i][0];
                count++;
            }
        }
        return count+1;
    }
};