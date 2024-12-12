class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        // sort(events.begin(),events.end(),comp);
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0; int ind=0;
        
        for(int i=1;i<1e5+1;i++){
            while(ind<n && events[ind][0]==i){
                pq.push(events[ind][1]); ind++;
            }
            while(!pq.empty() && pq.top()<i) pq.pop();
            if(!pq.empty()){ans++; pq.pop();}

            if(ind>=n && pq.empty()) break;
        }
        return ans;

        // int count=1;
        // int prev=events[0][0]+1;
        // for(int i=1;i<n;i++){
        //     if(events[i][1]>=prev){
        //         prev++; count++;
        //     }
        // }
        // return count;
    }
};