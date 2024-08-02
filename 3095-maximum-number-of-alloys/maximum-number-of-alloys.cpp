class Solution {
public:
    bool f(int n, int mid, int budget, vector<int> &comp, vector<int> &stock, vector<int> &cost){
        long long neededCost=0;
        for(int i=0;i<n;i++){
            long long need=max(0LL,(long long)mid*comp[i]-stock[i]);
            neededCost+=need*cost[i];
        }
        return neededCost<=(long long)budget;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int maxi=0;
        for(auto i:composition){
            int s=0;int e=1e9;
            int number=0;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(f(n,mid,budget,i,stock,cost)){
                    s=mid+1;
                    number=mid;
                }
                else e=mid-1;
            }
            maxi=max(maxi,number);
        }
        return maxi;
    }
};