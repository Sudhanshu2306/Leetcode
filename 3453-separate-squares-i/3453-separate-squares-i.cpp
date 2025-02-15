class Solution {
public:
    double separateSquares(vector<vector<int>>& a) {
        double s=0,e=1e12;
        double ans=e;
        while(s+0.000001<e){
            double mid=s+(e-s)/2;
            double totArea=0;
            for(auto &it:a){
                double x=it[0],y=it[1],side=it[2];
                double top_right=y+side;

                if(top_right<=mid) totArea+=(double)side*side;
                else if(y>=mid){
                    totArea-=(double)side*side;
                }
                else{
                    totArea+=(double)side*(mid-y);
                    totArea-=(double)side*(top_right-mid);
                }
            }
            if(totArea>=0){
                e=mid;
                ans=mid;
            } 
            else s=mid;
        }
        return ans;
    }
};