class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        string s="";
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                if(words[i][j]==separator){
                    ans.push_back(s);
                    s="";
                }
                else s+=words[i][j];
            }
            if(s!="") {
                ans.push_back(s);
                s="";
            }
        }
        vector<string> res;
        for(string it:ans){
            if(it!="") res.push_back(it);
        }
        return res;
    }
};