class Solution {
public:
    bool isPalindrome(string s){
        string x=s;
        reverse(s.begin(),s.end());
        return s==x;
    }
    
    void recursion(string s, int index, vector<vector<string>> &ans, vector<string> &res){
        if(index==s.length()){
            ans.push_back(res);
            return;
        }
        
        for(int i=index;i<s.length();i++){
            string x=s.substr(index,i-index+1);
            if(isPalindrome(x)){
                res.push_back(x);
                recursion(s,i+1,ans,res);
                res.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        recursion(s,0,ans,res);
        return ans;
    }
};