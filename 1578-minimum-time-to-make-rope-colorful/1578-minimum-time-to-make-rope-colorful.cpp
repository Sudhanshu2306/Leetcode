class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int n=neededTime.size();
        int i=0,j=0;
        while(i<n && j<n){
            int maxi=0;
            int sum=0;
            while(j<n && colors[i]==colors[j]){
                maxi=max(maxi,neededTime[j]);
                sum+=neededTime[j];
                j++;
            }
            ans+=(sum-maxi);
            i=j;
        }
        return ans;
    }
};