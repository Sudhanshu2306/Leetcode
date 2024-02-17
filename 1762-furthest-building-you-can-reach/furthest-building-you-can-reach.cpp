class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=heights.size();
        int b=0;
        for(int i=1;i<n;i++){
            int x=heights[i]-heights[i-1];
            if(x<=0) continue;

            if(pq.size()<ladders) pq.push(x);
            else if(ladders==0 || x<=pq.top()) b+=x;
            else{
                b+=pq.top(); pq.pop();
                pq.push(x);
            }
            if(b>bricks) return i-1;
        }
        return n-1;
    }
};