class Solution {
public:
    int possibleStringCount(string word) {
        map<char,int> mp;
        for(auto it:word) mp[it]++;
        int count=0;
        for(auto it:mp){
            count+=(it.second-1);
        }
        return count+1;
    }
};