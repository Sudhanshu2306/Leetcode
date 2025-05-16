typedef tuple<int,int,int> ti;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        int maxi=-1e5-1;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],i,0});
            maxi=max(maxi,nums[i][0]);
        }
        int s=0,e=1e5+1;

        while(true){
            auto [curr,r,c]=pq.top(); pq.pop();
            if(e-s>maxi-curr){
                e=maxi,s=curr;
            }
            if(c<nums[r].size()-1){
                pq.push({nums[r][c+1],r,c+1});
                maxi=max(maxi,nums[r][c+1]);
            }
            else break;   
        }
        return {s,e};
    }
};