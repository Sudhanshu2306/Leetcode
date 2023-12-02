class Solution {
public:
    
    bool solve(string &s, vector<int> &a){
        vector<int> b(26,0);
        for(int i=0;i<s.length();i++){
            b[s[i]-'a']++;                
            if(b[s[i]-'a']>a[s[i]-'a']){
                return false;
            }
        }
        return true;
    }
        
    
    int countCharacters(vector<string>& words, string chars) {
        vector<int> a(26,0);
        for(auto ch:chars){
            a[ch-'a']++;
        }
        int ans=0;
        for(string x:words){
            if(solve(x,a)){
                ans+=x.length();
            }
        }
        return ans;
    }
};