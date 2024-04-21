class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp1, mp2;
        int n=word.size();
        int ans = 0;
        for (int i=0;i<n;i++) {
            char ch = tolower(word[i]);
            
            if (islower(word[i])) {
                mp1[ch] = i;
            } 
            else {
                if (mp2.find(ch) == mp2.end()) {
                    mp2[ch] = i;
                }
            }
        }
        for (auto &i : mp1) {
            if (mp2.find(i.first) != mp2.end() && i.second < mp2[i.first]) {
                ans++;
            }
        }
        return ans;
    }
};