class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        vector<int> x(n+1,0);

        sort(q.begin(),q.end());
        priority_queue<int> pq;
        int count=0;
        int j=0;
        for(int i=0;i<n;i++){
            count+=x[i];
            while(j<q.size() && q[j][0]==i){
                pq.push(q[j][1]); j++;
            }
            while(!pq.empty() && count<nums[i] && pq.top()>=i){
                count++; x[pq.top()+1]--;
                pq.pop();
            }
            if(count<nums[i]) return -1;
        }
        return pq.size();
    }
};