typedef long long ll;

class Solution {
public:
    long long calculateScore(string s) {
        ll n=s.size();
        map<int,vector<int>> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int a=s[i]-'a';
            if(mp.find((25-a))!=mp.end() && mp[25-a].size()>0){
                ans+=(i-mp[25-a].back());
                mp[25-a].pop_back();
            } 
            else mp[a].push_back(i);
        }
        return ans;
    }
};