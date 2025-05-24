class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int ans=0;
        int x=0;
        for(int i=0;i<n;i++){
            x+=(gas[i]-cost[i]);
            if(x<0){
                x=0;
                ans=(i+1)%n;
            }
        }
        int z=accumulate(gas.begin(),gas.end(),0);
        int y=accumulate(cost.begin(),cost.end(),0);

        if(y>z) return -1;
        return ans;
    }
};