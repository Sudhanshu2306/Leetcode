class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.length();
        unordered_map<char,int> mp;
        int i=0;
        for(int j=0;j<n;j++){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};