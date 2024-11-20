class Solution {
public:
    int takeCharacters(string s, int k) {
        map<char,int> mp;
        int n=s.size();
        for(auto it:s) mp[it]++;
        int ca=0,cb=0,cc=0;
        if(mp['a']>=k) ca=1; if(mp['b']>=k) cb=1; if(mp['c']>=k) cc=1;
        
        if(!(ca&&cb&&cc)) return -1;
        int mini=n;
        int i=n-1; int j=n-1;
        while(i>=0){
            mp[s[i]]--;
            while(mp['a']<k || mp['b']<k || mp['c']<k){
                mp[s[j]]++; j--;
            }
            mini=min(mini,n-1+i-j);
            i--;
        }
        return mini;
    }
};