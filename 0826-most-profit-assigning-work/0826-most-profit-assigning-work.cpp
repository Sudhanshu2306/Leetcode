class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans=0;
        int maxi=0;
        int n=worker.size();
        int m=profit.size();
        unordered_map<int,int> mp;
        sort(difficulty.begin(),difficulty.end());
        for(int i=0;i<m;i++){
            maxi=max(maxi,profit[i]);
            mp[difficulty[i]]=maxi;
        }
        
        for(int i=0;i<n;i++){
            int x=upper_bound(difficulty.begin(),difficulty.end(),worker[i])-difficulty.begin();
            if(x==0) ans+=0;
            else if(x>n-1) ans+=mp[difficulty[m-1]];
            else ans+=mp[difficulty[x-1]];
        }
        return ans;
    }
};