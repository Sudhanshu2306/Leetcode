class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int> mp;
        int count=0;
        for(auto it:matrix){
            string x="";
            for(int i=0;i<it.size();i++){
                if(it[i]!=it[0]) x+='0';
                else x+='1';
            }
            mp[x]++;
        }
        for(auto it:mp) count=max(count,it.second);
        return count;
    }

};