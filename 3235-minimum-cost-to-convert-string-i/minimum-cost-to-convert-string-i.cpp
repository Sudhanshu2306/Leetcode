#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<int, vector<pair<int, int>>> adj;
        int n = original.size();
        
        // Build the adjacency list
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({v, cost[i]});
        }

        vector<vector<ll>> dist(26, vector<ll>(26, 1e9));

        // Run Dijkstra's algorithm from each node
        for (int i = 0; i < 26; i++) {
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
            vector<ll> temp(26, 1e9);

            pq.push({0, i});
            temp[i] = 0;

            while (!pq.empty()) {
                auto x = pq.top(); pq.pop();
                ll wt = x.first;
                int node = x.second;

                if (wt > temp[node]) continue;

                for (auto it : adj[node]) {
                    int adjNode = it.first;
                    ll edwt = it.second;

                    if (edwt + wt < temp[adjNode]) {
                        temp[adjNode] = edwt + wt;
                        pq.push({temp[adjNode], adjNode});
                    }
                }
            }
            dist[i] = temp;
        }

        ll ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                if (dist[source[i] - 'a'][target[i] - 'a'] == 1e9) return -1;
                ans += dist[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return ans;
    }
};