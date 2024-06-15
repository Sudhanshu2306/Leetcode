class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        priority_queue<int> pqmax;
        int n=profits.size();
        for(int i=0;i<n;i++){
            if(capital[i]<=w) pqmax.push(profits[i]);
            else pq.push({capital[i],profits[i]});
        }

        while(k){
            if(pqmax.empty()) return w;
            w+=pqmax.top(); pqmax.pop();

            while(!pq.empty() && pq.top().first <=w){
                int profit=pq.top().second;
                pq.pop();
                pqmax.push(profit);
            }
            k--;
        }
        return w;
    }
};