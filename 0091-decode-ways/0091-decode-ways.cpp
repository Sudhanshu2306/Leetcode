class Solution {
//     dp problem, not solved, watched video, revisit again!
private:
    
    int dfs(int i, const string& s, unordered_map<int, int>& dp) {
        if (i == s.size()) {
            return 1;  // reached the end, one way to decode
        }

        if (dp.find(i) != dp.end()) {
            return dp[i];
        }

        if (s[i] == '0') {
            return 0;
        }

        int res = dfs(i + 1, s, dp);

        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))) {
            res += dfs(i + 2, s, dp);
        }

        dp[i] = res;
        return res;
    }
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }

        unordered_map<int, int> dp;
        return dfs(0, s, dp);
    }
};