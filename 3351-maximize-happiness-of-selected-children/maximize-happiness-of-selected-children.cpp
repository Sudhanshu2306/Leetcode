class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        for(auto i:happiness){
            pq.push(i);
        }
        long long sum=0;
        int d=0;
        while(!pq.empty()){
            int x=pq.top(); pq.pop();
            sum+=max(0LL,(long long)(x-d)); d++;
            k--;
            if(k==0)break;
        }
        return sum;
    }
};