class Solution {
public:
    long long countCompleteDayPairs(vector<int>& a) {
        unordered_map<int,int> mp;
        int n=a.size();
        int count=0;

        for(int i=0;i<n;i++){
            int x=a[i]%24;
            int y=(24-x)%24;

            if(mp.find(y)!=mp.end()) count+=mp[y];
            mp[x]++;
        }
        return count;
    }
};