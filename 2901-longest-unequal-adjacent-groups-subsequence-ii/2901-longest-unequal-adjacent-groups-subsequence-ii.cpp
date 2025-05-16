class Solution {
public:
    bool f(string x, string y){
        int count=0;
        for(auto i=0;i<x.size();i++){
            count+=(x[i]!=y[i]);
        }
        return count==1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int> dp(n+1,1);
        vector<int> ind(n+1,-1);
        int maxi=1, maxind=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(words[i].size()==words[j].size() && groups[i]!=groups[j] && f(words[i],words[j])){
                    if(1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        ind[i]=j; // for tracking the dp table
                        if(dp[i]>maxi){
                            maxi=dp[i]; maxind=i;
                        }
                    }
                }
            }
        }
        vector<string> ans;
        ans.push_back(words[maxind]);
        while(ind[maxind]!=-1){
            ans.push_back(words[ind[maxind]]);
            maxind=ind[maxind];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};