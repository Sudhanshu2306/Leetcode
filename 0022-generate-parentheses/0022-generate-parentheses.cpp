class Solution {
public:
    void f(int i, vector<string> &ans, string x, int count){
        if(i==0 && count==0){
            ans.push_back(x); return;
        }
        if(count>0) f(i,ans,x+")",count-1);
        if(i>0) f(i-1,ans,x+"(",count+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string x="";
        f(n,ans,x,0);
        return ans;
    }
};