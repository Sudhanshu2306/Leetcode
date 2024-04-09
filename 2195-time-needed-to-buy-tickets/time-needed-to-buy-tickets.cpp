class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        int x=tickets[k];
        int n=tickets.size();
        for(int i=0;i<=k;i++){
            time+=min(tickets[i],x);
        }
        for(int i=k+1;i<n;i++){
            time+=min(tickets[i],tickets[k]-1);
        }
        return time;
    }
};