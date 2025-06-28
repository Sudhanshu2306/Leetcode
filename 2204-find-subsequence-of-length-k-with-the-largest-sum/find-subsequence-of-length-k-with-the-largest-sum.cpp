typedef pair<int,int> p;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            if(pq.size()>k) pq.pop();
        } 
        priority_queue<p,vector<p>,greater<p>> x;
        while(!pq.empty()){
            x.push({pq.top().second,pq.top().first});
            pq.pop();
        }
        while(!x.empty()){
            ans.push_back(x.top().second);
            x.pop();
        }
        return ans;
    }
};