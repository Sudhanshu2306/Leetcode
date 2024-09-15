class Solution {
public:
    int findTheLongestSubstring(string s) {
        // from the hints provided, we would need a 5-bit number, basically a bit mask
        int bitmask=0;
        unordered_map<char,int> mp;
        mp['a']=0;mp['e']=1;mp['i']=2;mp['o']=3;mp['u']=4;
        unordered_map<char,int> hash; hash[bitmask]=-1;
        int maxLen=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(mp.find(ch)!=mp.end()) {
                int ind=mp[ch];
                bitmask^=(1<<ind);
            }
            if(hash.find(bitmask)==hash.end()){
                hash[bitmask]=i;
            }
            else{
                maxLen=max(maxLen,i-hash[bitmask]);
            }
        }
        return maxLen;
    }
};