class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> mp;
        int mini=1e9+1;
        for(auto it:basket1){
            mini=min(mini,it);
            mp[it]++;
        } 
        for(auto it:basket2){
            mini=min(mini,it);
            mp[it]--;
        } 

        vector<int> x;
        for(auto it:mp){
            if(it.second%2==1) return -1;
            else{
                for(int i=0;i<abs(it.second)/2;i++) x.push_back(it.first);
            }
        }
        sort(x.begin(),x.end());
        long long ans=0;
        for(int i=0;i<x.size()/2;i++) ans+=min(x[i],2*mini);
        return ans;
    }
};