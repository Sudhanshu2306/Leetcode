class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(n!=m) return false;
        
        vector<int> mp1(26,0) ,mp2(26,0);
        for(auto i:word1) mp1[i-'a']++;
        for(auto i:word2) mp2[i-'a']++;
        
        for(int i=0;i<26;i++){
            if((mp1[i]>0 && mp2[i]==0) || (mp1[i]==0 && mp2[i]>0)) return false;
        }
        
        sort(mp1.begin(),mp1.end());
        sort(mp2.begin(),mp2.end());
        
        for(int i=0;i<26;i++){
            if(mp1[i]!=mp2[i]) return false;
        }
        return true;
    }
};