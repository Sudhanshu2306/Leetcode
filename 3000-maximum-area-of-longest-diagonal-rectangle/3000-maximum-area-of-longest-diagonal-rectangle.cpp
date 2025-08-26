class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=INT_MIN;
        int maxi=0, maxD=0;
        for(auto it:dimensions){
            int l=it[0], b=it[1];
            int dsquar=pow(l,2)+pow(b,2);
            if(dsquar>maxD){
                maxD=dsquar; maxi=l*b;
            }
            else if(dsquar==maxD) maxi=max(maxi,l*b);
        }
        return maxi;
    }
};