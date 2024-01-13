class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mp1(26,0), mp2(26,0);
        for(auto c:s)
            mp1[c-'a']++;
        
        int count=0;
        for(auto c:t)
            mp2[c-'a']++;
          
        for(int i=0;i<26;i++){
            if(mp2[i]<mp1[i])
                count+=(mp1[i]-mp2[i]);
        }
        return count;
    }
};