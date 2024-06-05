class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, INT_MAX); 
        
        for (string word : words) {
            vector<int> mp(26, 0);
            for (char c : word) {
                mp[c - 'a']++;
            }
            
            for (int i = 0; i < 26; i++) {
                freq[i] = min(freq[i], mp[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freq[i]; j++) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;

    }
};