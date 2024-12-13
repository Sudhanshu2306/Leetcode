class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score=0;
        int n=nums.size();

        vector<int> vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++) pq.push({nums[i],i});

        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            int y=x.first; int ind=x.second;

            if(!vis[ind]){
                vis[ind]=true;
                score+=y;
                if(ind-1>=0) vis[ind-1]=true;
                if(ind+1<n) vis[ind+1]=true;
            }
        }
        return score;
    }
};