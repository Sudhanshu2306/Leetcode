class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        int maxi=0;
        int ans=0;

        for(int i=0;i<n;i++){
            while(!pq.empty() && events[i][0]>pq.top().first){
                maxi=max(maxi,pq.top().second); pq.pop();
            }
            pq.push({events[i][1],events[i][2]});
            ans=max(events[i][2]+maxi,ans);
        }
        return ans;
    }
};