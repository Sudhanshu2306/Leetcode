class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto x=pq.top(); pq.pop();
            int y=x.first*m;
            pq.push({y,x.second});
        }
        vector<int> ans(nums.size());
        while(!pq.empty()){
            ans[pq.top().second]=(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};