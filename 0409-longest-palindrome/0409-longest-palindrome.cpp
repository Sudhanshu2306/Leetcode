class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=0; int maxi=0;
        for(auto i:mp){
            if(i.second%2==0) ans+=i.second;
            else maxi=max(maxi,i.second);
        }
        return ans+maxi;
    }
};