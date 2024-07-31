class Solution {
public:
    void f(int ind, string s, vector<string>& wordDict, string temp, vector<string> &ans){
        if(ind==s.size()){
            ans.push_back(temp.substr(1));
            return;
        }
        string word="";
        for(int i=ind;i<s.size();i++){
            word+=s[i];
            for(int j=0;j<wordDict.size();j++){
                if(word==wordDict[j]){
                    f(i+1,s,wordDict,temp+" "+word,ans);
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        f(0,s,wordDict,"",ans);
        return ans;
    }
};