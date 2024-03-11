class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        vector<bool> vis(26,false);
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        string ans="";
        for(int i=0;i<order.length();i++){
            if(mp.find(order[i])!=mp.end()){
                string x=string(mp[order[i]],order[i]);
                ans+=x;
                vis[order[i]-'a']=true;
            }
        }
        for(int i=0;i<s.length();i++){
            if(!vis[s[i]-'a'] && mp.find(s[i])!=mp.end()) ans+=s[i];
        }
        return ans;
    }
};