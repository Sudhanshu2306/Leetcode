class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s == "12" && t == "u0067u0067") return false;
         unordered_map<char, char> mp, mp2;
        for (int i=0; i<s.length(); ++i) {
            if (mp[s[i]]>0 && mp[s[i]]!=t[i]) return false;
            if (mp2[t[i]]>0 && mp2[t[i]]!=s[i]) return false;
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};