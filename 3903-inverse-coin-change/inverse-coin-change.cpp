class Solution {
public:
    vector<int> findCoins(vector<int>& a) {
        int maxi=*max_element(a.begin(),a.end());
        int n=a.size();
        vector<int> dp(n+1,0);
        vector<int> ans;

        vector<int> ways(n+1,0);
        for(int i=1;i<=n;i++) ways[i]=a[i-1];
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(dp[i]==ways[i]) continue;
            else if(dp[i]<ways[i]){
                ans.push_back(i);
                for(int j=i;j<=n;j++) dp[j]+=dp[j-i];
                if(dp[i]<ways[i]) return {};
            }
            else return {};
        }
        return ans;
    }
};