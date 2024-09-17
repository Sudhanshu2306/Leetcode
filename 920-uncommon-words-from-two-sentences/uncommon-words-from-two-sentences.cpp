class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> mp;
        string x=s1+" "+s2+" ";
        string y="";
        for(int i=0;i<x.size();i++){
            if(x[i]!=' ') y+=x[i];
            else {
                mp[y]++;
                y="";
            }
        }
        for(auto i:mp){
            if(i.second==1) ans.push_back(i.first);
        }
        return ans;
    }
};