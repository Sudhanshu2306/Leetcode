class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int i=0,j=0;
        int n=neededTime.size();
        while(i<n && j<n){
            int total=0;
            int maxi=0;
            while(colors[i]==colors[j] && j<n){
                total+=neededTime[j];
                maxi=max(maxi,neededTime[j]);
                j++;
            }
            i=j;
            ans+=(total-maxi);
        }
        return ans;
    }
};