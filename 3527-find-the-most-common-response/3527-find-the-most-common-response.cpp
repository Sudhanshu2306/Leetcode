class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string,int> mp;
        for(auto it:responses){
            map<string,int> x;
            for(auto i:it){
                if(x.find(i)==x.end()) x[i]=1;
            }
            for(auto itr:x) mp[itr.first]++;
        }
        string ans;
        int maxi=0;
        for(auto it:mp){
            if(it.second>maxi){
                maxi=it.second; ans=it.first;
            }
        }
        return ans;
    }
};