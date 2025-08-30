typedef long long ll;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        vector<pair<int,int>> x;
        for(int i=0;i<n;i++){
            x.push_back({spells[i],i});
        }
        sort(x.begin(),x.end());

        int i=0;
        vector<int> ans(n,0);
        sort(potions.begin(),potions.end());
        int m=potions.size();
        for(int i=0;i<n;i++){
            double y=((success+x[i].first-1)/x[i].first);
            auto it=lower_bound(potions.begin(),potions.end(),y);
            // cout<<it<<" ";
            // if(it==potions.begin()) ans[x[i].second]=0;
            // else{
                int z=it-potions.begin();
                ans[x[i].second]=m-z;
            // }
        }
        return ans;
    }
};