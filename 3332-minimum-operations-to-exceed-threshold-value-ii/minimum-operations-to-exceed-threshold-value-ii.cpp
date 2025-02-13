typedef long long ll;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(auto i:nums) pq.push(i);

        ll count=0;
        while(pq.top()<k){
            ll x=pq.top(); pq.pop(); 
            ll y=pq.top(); pq.pop();
            ll z=2*min(x,y)+max(x,y);
            pq.push(z);
            count++;
        }
        return count;
    }
};