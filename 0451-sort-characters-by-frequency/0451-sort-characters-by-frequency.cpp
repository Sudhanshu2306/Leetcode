class Solution {
public:

    bool comp(auto &a, auto &b){
        return a.second<b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> arr(mp.begin(),mp.end());
        sort(arr.begin(),arr.end(),[](auto& a,auto& b){
            return a.second>b.second;
        });
        string ans="";
        for(auto i:arr){
            string x=string(i.second,i.first);
            ans+=x;
        }
        return ans;
    }
};