class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        priority_queue<pair<int,int>> pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pqx;
        for(int i=0;i<a.size();i++){
            pq.push({a[i][a[i].size()-1],i});
            pqx.push({a[i][0],i});
        }
        auto x1=pq.top(); pq.pop();
        auto y1=pqx.top(); pqx.pop();
        if(x1.second!=y1.second) return x1.first-y1.first;
        else{
            auto x2=pq.top(); auto y2=pqx.top();
            return max(x1.first-y2.first,x2.first-y1.first);
        }
    }
};