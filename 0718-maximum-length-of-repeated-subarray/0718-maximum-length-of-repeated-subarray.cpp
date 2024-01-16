class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(); int m=nums2.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0),curr(m+1,0);
        
        for(int i=0;i<=m;i++) prev[i]=0;
        // for(int i=0;i<=m;i++) dp[0][i]=0;
        int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]) curr[j]=prev[j-1]+1;
                else curr[j]=0;
                maxi=max(maxi,curr[j]);
            }
            prev=curr;
        }
        return maxi;
    }
};