class Solution {
public:
    
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comparator);

        int x=points[0][1];

        int ans=1;
        int n=points.size();
        for(int i=1;i<n;i++){
            if(x<points[i][0]){
                x=points[i][1];
                ans++;
            }
        }
        return ans;
    }
};