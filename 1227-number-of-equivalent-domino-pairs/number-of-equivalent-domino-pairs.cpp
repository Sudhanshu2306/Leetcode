class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> mp;
        int count=0;
        for(auto it:dominoes){
            int a=it[0],b=it[1];
            if(mp.find({a,b})!=mp.end()) count+=mp[{a,b}];
            if(mp.find({b,a})!=mp.end() && a!=b) count+=mp[{b,a}];
            mp[{a,b}]++;
        }
        return count;
    }
};