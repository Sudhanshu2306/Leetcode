class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // ceil is like smallest integer function, returns smallest integer greater than or equal to given no.
        priority_queue<unsigned long long> pq;
        for(auto i:nums){
            pq.push(i);
        }
        unsigned long long score=0;
        while(k--){
            score+=(pq.top());
            pq.push(pq.top()%3==0?pq.top()/3:pq.top()/3+1);
            pq.pop();
        }
        return score;
    }
};