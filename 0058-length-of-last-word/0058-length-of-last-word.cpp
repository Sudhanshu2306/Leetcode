class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans="";
        int count=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                count++;
            }
            else{
                break;
            }
        }
        for(int i=s.length()-1-count;i>=0;i--){
            if(s[i]!=' '){
                ans.push_back(s[i]);
            }
            else{
                break;
            }
        }
        return ans.length();
    }
};