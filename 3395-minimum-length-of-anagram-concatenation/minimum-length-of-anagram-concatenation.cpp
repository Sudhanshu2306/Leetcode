class Solution {
public:
    int minAnagramLength(string s) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        char ch=s[0];
        int x=mp[ch];
        for(auto it:mp){
            x=__gcd(x,it.second);
        }
        int ans=0;
        for(auto i:mp){
            if(i.second>=x){
                ans+=(i.second/x);
            }
        }
        return ans;
    }
};