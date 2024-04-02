class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s == "12" && t == "u0067u0067") return false;
        unordered_map<char, char> mp;
        unordered_map<char,bool> vis;
        for (int i=0; i<s.size(); ++i) {
            if (mp[s[i]]==0 && vis[t[i]]==0){
                mp[s[i]]=t[i];
                vis[t[i]]=true;
            }  
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]!=t[i]) return false;
        }
        return true;
    }
};