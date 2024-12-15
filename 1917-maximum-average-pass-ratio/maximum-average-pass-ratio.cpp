class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int e) {
        int n=classes.size();
        priority_queue<pair<double,pair<int,int>>> pq;

        for(auto it:classes){
            double x=(1.0*(it[0]+1))/(it[1]+1)-(1.0*it[0]/it[1]);
            pq.push({x,{it[0]+1,it[1]+1}});
        }
        while(e--){
            auto temp=pq.top(); pq.pop();
            int num=temp.second.first;
            int den=temp.second.second;

            double x=((1.0*(num+1))/(den+1))-(num*1.0/den);
            pq.push({x,{num+1,den+1}});
        }

        double ans=0.0;
        while(!pq.empty()){
            auto temp=pq.top(); pq.pop();
            int num=temp.second.first-1;
            int den=temp.second.second-1;
            ans+=(num*1.0/den);
        }
        ans=ans*1.0/n;
        return ans;
    }
};