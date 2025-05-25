class Solution {
public:
    int maxSubstrings(string word) {
        int count=0;
        vector<int> ind(26,-1);
        for(int i=0;i<word.size();i++){
            int x=word[i]-'a';
            if(ind[x]!=-1 && i-ind[x]>=3){
                count++;
                for(int k=0;k<26;k++) ind[k]=-1;
            }
            else if(ind[x]==-1) ind[x]=i;
        }
        return count;
    }
};