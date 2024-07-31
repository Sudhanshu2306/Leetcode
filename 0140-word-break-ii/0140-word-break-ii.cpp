class TrieNode {
public:
    TrieNode* links[26];
    bool flag = false;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }
};

class Solution {
public:
    TrieNode* root;

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->links[word[i] - 'a'] == nullptr) {
                node->links[word[i] - 'a'] = new TrieNode();
            }
            node = node->links[word[i] - 'a'];
        }
        node->flag = true;
    }

    void f(int ind, TrieNode* node, vector<string>& ans, string s, string store) {
        if (node->flag) {
            if (ind == s.size()) {
                ans.push_back(store);
                return;
            }
            f(ind, root, ans, s, store + " ");
        }

        if (ind >= s.size()) return;
        char ch = s[ind];
        if (node->links[ch - 'a'] != nullptr) {
            f(ind + 1, node->links[ch - 'a'], ans, s, store + ch);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        root = new TrieNode();

        for (int i = 0; i < wordDict.size(); i++) {
            insert(wordDict[i]);
        }
        f(0, root, ans, s, "");
        return ans;
    }
};
