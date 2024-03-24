class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int w=0;
        int maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[w]]--;
                w++;
            }
            maxi=max(maxi,i-w+1);
        }
        return maxi;
    }
};