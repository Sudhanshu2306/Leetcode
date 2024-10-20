class Solution {
public:
    vector<string> stringSequence(string s) {
        int n=s.size();
        
        int ans=0;
        string x="";
        vector<string> res;
        // res.push_back(x+curr);
        for(int i = 0; i < n;i++) {
            char curr='a';
            while(curr != s[i]){
                res.push_back(x + curr); 
                if(curr == 'z') curr = 'a';
                else curr++;
            }
            x += curr;
            res.push_back(x);
        }
        return res;
    }
};