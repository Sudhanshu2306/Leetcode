class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            map<char, int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                for(auto it:mp){
                    if(it.second>=k){
                        ans++; break;
                    }
                }
            }
        }
        return ans;
    }
};