class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=searchWord.size();
        string x="";
        int count=1;
        for(auto it:sentence){
            if(it==' ') x="",count++;
            else x+=it;
            if(x.size()>=n){
                if(x.substr(0,n)==searchWord) return count;
            }
        }
        return -1;
    }
};