class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int count=0;
        
        for(int i=1;i<word.length();i++){
            if(word[i]==word[i-1] || abs(word[i]-word[i-1])==1){
                count++;
                i+=1;
            }
        }
        return count;
    }
};