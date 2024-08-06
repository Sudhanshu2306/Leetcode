class Solution {

private:
    void solve(int ind,string x,vector<string> mapping,string digits,vector<string>&ans){
        if(ind>=digits.size()){
            ans.push_back(x); return;
        }

        int num=digits[ind]-'0';
        for(int i=0;i<mapping[num].size();i++){
            x+=(mapping[num][i]);
            solve(ind+1,x,mapping,digits,ans);
            x.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        // vector<string> ans;
        solve(0,"",mapping,digits,ans);

        return ans;
    }
};