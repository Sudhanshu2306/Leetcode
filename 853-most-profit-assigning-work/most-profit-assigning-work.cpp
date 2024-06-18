class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans=0;
        int maxi=0;
        int n=worker.size();
        int m=profit.size();
        map<int,int> mp;
        // sort(difficulty.begin(),difficulty.end());
        for(int i=0;i<m;i++){
            // maxi=max(maxi,profit[i]);

            mp[difficulty[i]]=max(mp[difficulty[i]],profit[i]);
        }

        int maxVal = INT_MIN;
        for(auto i: mp) {
            int val = i.second;
            maxVal = max(maxVal, val);
            mp[i.first] = maxVal;
        }
        
        for(int i=0;i<n;i++){
            auto x=mp.upper_bound(worker[i]);
            // if(x==0) ans+=0;
            
            if(x!=mp.begin()){
                x--;
                ans+=x->second;
            }
        }
        return ans;
    }
};