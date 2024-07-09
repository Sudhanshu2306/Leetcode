class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time=customers[0][0];
        double waiting_time=0;
        double n=customers.size();
        for(int i=0;i<n;i++){
            if(time<customers[i][0]){
                time=customers[i][0];
            } 
            time+=customers[i][1];
            waiting_time+=(time-customers[i][0]);
            cout<<time-customers[i][0]<<" ";
        }
        double x=waiting_time/n;
        return x;
    }
};