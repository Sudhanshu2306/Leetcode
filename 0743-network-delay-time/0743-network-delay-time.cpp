class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[0]=0;
        dist[k]=0;
        for(int i=0;i<n;i++){
            for(auto it:times){
                int u=it[0],v=it[1], w=it[2];
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]) dist[v]=dist[u]+w;
            }
        }
        int maxi=0;
        for(auto it:dist) maxi=max(maxi,it);
        return maxi==INT_MAX?-1:maxi;
    }
};