class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& arr) {
        map<int,pair<int,int>> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int w=arr[i][0]; int l=arr[i][1];
            // zero(0) for losses and one(1) for wins
            mp[l].second+=1;
            mp[w].first+=1;
        }
        
        vector<vector<int>> ans(2);
        for(auto i:mp){
            if(i.second.second==1) ans[1].push_back(i.first);
            if(i.second.second==0) ans[0].push_back(i.first);
        }
        return ans;
    }
};