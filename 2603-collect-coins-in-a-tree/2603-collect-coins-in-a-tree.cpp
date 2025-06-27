class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<vector<int>> adj(n);
        for (auto it:edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> deg(n);
        for (int i = 0; i < n; ++i) deg[i] = adj[i].size();
        vector<char> removed(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) if (deg[i] == 1 && coins[i] == 0) q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (removed[v]) continue;
            removed[v] = 1;
            for (int u : adj[v]) {
                if (removed[u]) continue;
                if (--deg[u] == 1 && coins[u] == 0) q.push(u);
            }
        }
        vector<int> cur;
        for (int i = 0; i < n; ++i) if (!removed[i] && deg[i] == 1) cur.push_back(i);
        for (int step = 0; step < 2; ++step) {
            vector<int> nxt;
            for (int v : cur) {
                if (removed[v]) continue;
                removed[v] = 1;
                for (int u : adj[v]) {
                    if (removed[u]) continue;
                    if (--deg[u] == 1) nxt.push_back(u);
                }
            }
            cur.swap(nxt);
        }
        long long count = 0;
        for (int i = 0; i < n; ++i) if (!removed[i]) count += deg[i];
        count /= 1;
        return count ? count * 2 : 0;
    }
};