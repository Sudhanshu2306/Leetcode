class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, vector<int> &a, map<int,int> &mp){
        if(mp.find(a[i]+a[j])==mp.end()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=1+f(j,mp[a[i]+a[j]],a,mp);
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        dp.resize(1e3+1,vector<int>(1e3+1,-1));
        map<int,int> mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]=i;

        int maxi=0;
        for(int i=0;i<arr.size()-2;i++){
            for(int j=i+1;j<arr.size()-1;j++){
                if(mp.find(arr[i]+arr[j])!=mp.end()) maxi=max(maxi,f(i,j,arr,mp));
            }
        }
        if(maxi>0) return maxi+2;
        else return 0;
    }
};