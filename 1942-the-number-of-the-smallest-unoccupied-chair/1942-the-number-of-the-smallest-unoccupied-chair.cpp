class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend){
        int n=times.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[times[i][0]]=i;
        sort(times.begin(),times.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<int> st;
        int ind=0;
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top().first<=times[i][0]){
                st.insert(pq.top().second); pq.pop();
            }
            if(!st.empty()){
                if(mp[times[i][0]]==targetFriend) return *st.begin();
                pq.push({times[i][1],*st.begin()});
                st.erase(*st.begin());
            }
            else{
                if(mp[times[i][0]]==targetFriend) return ind;
                pq.push({times[i][1],ind}); ind++;
            }
        }
        return -1;
    }
};