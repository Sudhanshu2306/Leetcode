class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=(gas[i]-cost[i]);
            if(sum<0){
                sum=0;
                ans=i+1;
            }
        }
        int x=accumulate(gas.begin(),gas.end(),0);
        int y=accumulate(cost.begin(),cost.end(),0);

        if(y>x) return -1;
        else return ans;
    }
};