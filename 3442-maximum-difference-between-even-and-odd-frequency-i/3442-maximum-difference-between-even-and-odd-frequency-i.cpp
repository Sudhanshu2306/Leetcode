class Solution {
public:
    int maxDifference(string s) {
        int maxi=0, mini=1e9;
        map<char,int> mp;
        for(auto it:s) mp[it]++;
        for(auto it:mp){
            if(it.second%2==0){
                mini=min(mini,it.second);
            } 
            else{
                maxi=max(maxi,it.second);
            }
        }
        return maxi-mini;
    }
};