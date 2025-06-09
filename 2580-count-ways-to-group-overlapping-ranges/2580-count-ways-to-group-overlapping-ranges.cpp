class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        int s=ranges[0][0], e=ranges[0][1];

        int n=ranges.size();
        int count=1;
        for(int i=1;i<n;i++){
            if(e>=ranges[i][0]){
                e=max(e,ranges[i][1]);
            }
            else{
                count++;
                s=ranges[i][0], e=ranges[i][1];
            }
        }
        return pow(2,count);
    }
};