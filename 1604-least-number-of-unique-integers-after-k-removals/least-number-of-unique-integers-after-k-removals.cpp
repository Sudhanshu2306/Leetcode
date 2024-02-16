class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto i:arr) mp[i]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        while(k--){
            int x=pq.top().first;
            int y=pq.top().second;
            pq.pop();
            if((x-1)>0) pq.push({x-1,y});
        }
        return pq.size();
    }
};