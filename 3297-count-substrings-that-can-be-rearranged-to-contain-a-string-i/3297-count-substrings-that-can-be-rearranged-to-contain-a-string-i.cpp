class Solution {
public:
    long long validSubstringCount(string w1, string w2) {
        unordered_map<char, int> c2, win;
        for (char c : w2) c2[c]++;
        
        long long res = 0;
        int l = 0, r = 0, m = c2.size(), frm = 0;

        while (r < w1.size()) {
            char ch = w1[r];
            win[ch]++;
            
            if (c2.count(ch) && win[ch] == c2[ch]) {
                frm++;
            }

            while (l <= r && frm == m) {
                res += (w1.size() - r);
                
                char lc = w1[l];
                win[lc]--;
                if (c2.count(lc) && win[lc] < c2[lc]) {
                    frm--;
                }
                l++;
            }
            r++;
        }
        
        return res;
    }
};