typedef pair<long long,long long> pii;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pii,vector<pii>,greater<pii>> pq; // for ending_time;
        priority_queue<long long,vector<long long>,greater<long long>> q; // for rooms
        for(int i=0;i<n;i++) q.push(i);
        vector<int> count(n,0);
        for(auto it:meetings){
            long long s=it[0], e=it[1];
            while(!pq.empty()){
                if(pq.top().first<=s){
                    q.push(pq.top().second);
                    pq.pop();
                }
                else break;
            }
            if(!q.empty()){
                pq.push({e,q.top()}); 
                count[q.top()]++;
                q.pop();
            }
            else{
                // while(!pq.empty()){
                //     if(pq.top().first<=s){
                //         q.push(pq.top().second);
                //         pq.pop();
                //     }
                //     else break;
                // }
                if(!q.empty()){
                    pq.push({e,q.top()}); 
                    count[q.top()]++;
                    q.pop();
                }
                else{
                    auto [en,rm]=pq.top(); pq.pop();
                    pq.push({e+max(0LL,en-s),rm});
                    count[rm]++;
                }
            }
        }
        int maxi=*max_element(count.begin(),count.end());
        for(int i=0;i<n;i++){
            // cout<<count[i]<<" ";
            if(count[i]==maxi) return i;
        }
        return 0;
    }
};