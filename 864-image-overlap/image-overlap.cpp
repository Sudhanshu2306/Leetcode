class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<pair<int,int>> x,y;
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1) x.push_back({i,j});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(b[i][j]==1) y.push_back({i,j});
            }
        }
        map<pair<int,int>,int> mp;
        for(auto it:x){
            for(auto itr:y){
                mp[{it.first-itr.first,it.second-itr.second}]++;
            }
        }
        int ans=0;
        for(auto it:mp) ans=max(ans,it.second);
        return ans;
    }
};