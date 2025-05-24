class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> mp;
        int count=0;
        for(auto it:time){
            int x=it%60;
            if(x==0) count+=mp[x];
            else count+=mp[60-x];
            
            mp[x]++;
        }
        return count;
    }
};