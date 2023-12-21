class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> ans;
        for (const auto& point : points) {
            ans.push_back(point[0]);
        }

        sort(ans.begin(), ans.end());

        int maxWidth = 0;
        for (int i = 0; i < ans.size() - 1; i++) {
            maxWidth = max(maxWidth, ans[i + 1] - ans[i]);
        }

        return maxWidth;        
    }
};