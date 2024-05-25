class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mpb; 
        unordered_map<int, int> mpc; 
        unordered_set<int> colors; 
        vector<int> ans;

        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];
            
            if (mpb.count(ball)) {
                int oldColor = mpb[ball];
                if (--mpc[oldColor] == 0) {
                    colors.erase(oldColor);
                }
            }
            mpb[ball] = color;
            if (++mpc[color] == 1) {
                colors.insert(color);
            }
            ans.push_back(colors.size());
        }

        return ans;
    }
};