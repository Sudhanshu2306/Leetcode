typedef pair<int, int> pi;

class Solution {
public:
    int f(int x1, int y1, int x2, int y2) {
        return abs(x2 - x1) + abs(y2 - y1);
    }

    int minimumCost(vector<int>& start, vector<int>& end, vector<vector<int>>& sr) {
        int n = sr.size();
        vector<int> dist(n, 1e9);
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for (int i = 0; i < n; i++) {
            int cost = f(start[0], start[1], sr[i][0], sr[i][1]) + sr[i][4];
            pq.push({cost, i});
        }

        while (!pq.empty()) {
            auto [w, ind] = pq.top(); pq.pop();

            if (w >= dist[ind]) continue;
            dist[ind] = w;

            for (int i = 0; i < n; i++) {
                if (i == ind) continue;
                int nextCost = w + f(sr[ind][2], sr[ind][3], sr[i][0], sr[i][1]) + sr[i][4];
                pq.push({nextCost, i});
            }
        }

        // Minimum of direct path vs. using teleport
        int ans = f(start[0], start[1], end[0], end[1]);
        for (int i = 0; i < n; i++) {
            int totalCost = dist[i] + f(sr[i][2], sr[i][3], end[0], end[1]);
            ans = min(ans, totalCost);
        }

        return ans;
    }
};
