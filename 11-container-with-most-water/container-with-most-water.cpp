class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=INT_MIN;

        int i=0,j=n-1;
        while(i<j){
            maxi=max(maxi,(j-i)*min(heights[i],heights[j]));
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return maxi;
    }
};