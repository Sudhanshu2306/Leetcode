class Solution {
public:
    double maxAmount(string ic, vector<vector<string>>& p1, vector<double>& r1, vector<vector<string>>& p2, vector<double>& r2) {
        unordered_map<string,double> mp;
        mp[ic]=1.0;
        int n=p1.size(),m=p2.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[p1[j][1]]=max(mp[p1[j][1]],mp[p1[j][0]]*r1[j]);
                mp[p1[j][0]]=max(mp[p1[j][0]],mp[p1[j][1]]/r1[j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                mp[p2[j][1]]=max(mp[p2[j][1]],mp[p2[j][0]]*r2[j]);
                mp[p2[j][0]]=max(mp[p2[j][0]],mp[p2[j][1]]/r2[j]);
            }
        }
        return mp[ic];
    }
};