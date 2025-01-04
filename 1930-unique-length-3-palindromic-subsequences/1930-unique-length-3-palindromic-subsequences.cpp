class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        unordered_set<char> letters;
        for (char c : s) letters.insert(c);
        
        for (char letter : letters) {
            int i = -1;
            int j = 0;
            
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) i = k;
                    j = k;
                }
            }
            
            unordered_set<char> in;
            for (int k = i + 1; k < j; k++) in.insert(s[k]);
            ans += in.size();
        }
        
        return ans;
    }
};