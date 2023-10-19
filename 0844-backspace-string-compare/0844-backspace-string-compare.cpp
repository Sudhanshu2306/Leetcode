class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ans1="";
        string ans2="";
        for(auto c: s){
            if(c=='#' && !ans1.empty()){
                ans1.pop_back();
            }
            else if(c!='#'){
                ans1.push_back(c);
            }
        }
        for(auto c: t){
            if(c=='#' && !ans2.empty()){
                ans2.pop_back();
            }
            else if(c!='#'){
                ans2.push_back(c);
            }
        }
        return ans1==ans2;
    }
};