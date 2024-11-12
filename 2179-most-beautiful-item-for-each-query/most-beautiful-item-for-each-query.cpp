class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int> mp;
        for(auto it:items){
            if(mp.find(it[0])==mp.end()) mp[it[0]]=it[1];
            else mp[it[0]]=(max(mp[it[0]],it[1]));
        }
        int n=mp.size();
        vector<int> prices;
        vector<int> pre;
        for(auto it:mp){
            prices.push_back(it.first);
            if(pre.empty()) pre.push_back(it.second);
            else pre.push_back(max(pre.back(), it.second));
        }

        vector<int> ans;
        for(auto it:queries){
            int x=upper_bound(prices.begin(),prices.end(),it)-prices.begin()-1;
            if(x>=0) ans.push_back(pre[x]);
            else ans.push_back(0);
        }
        return ans;
    }
};