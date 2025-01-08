class Solution {
public:
        bool pre(string s, string t){
            int i=0,j=0;
            while(i<s.length()){
                if(s[i]!=t[j]) return false;
                i++; j++;;
            }
            return true;
        }
        bool suf(string s, string t){
            int i=s.length()-1,j=t.length()-1;
            while(i>=0 ){
                if(s[i]!=t[j]) return false;
                i--; j--;
            }
            return true;
        }
        int countPrefixSuffixPairs(vector<string>& words) {
            int count=0;
            for(int i=0;i<words.size();i++){
                for(int j=i+1;j<words.size();j++){
                    if(pre(words[i],words[j]) && suf(words[i],words[j])) count++;
                }
            }
            return count;
        }
    
};