class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int p=0,p1=0,p2=0;
        for(int i=2;i<=n;i++){
            int c1=p1+cost[i-1];
            int c2=p2+cost[i-2];
            p=min(c1,c2);
            p2=p1;
            p1=p;
        }
        return p;
    }
};