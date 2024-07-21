class Solution {
public:
    vector<int> f(vector<vector<int>> &a, int k){
        vector<int> indegree(k);
        vector<vector<int>> adj(k);
        for (int i = 0; i < a.size(); i++) {
            adj[a[i][0] - 1].push_back(a[i][1] - 1);
            indegree[a[i][1] - 1]++;
        }

        queue<int> q;
        for (int i = 0; i < k; i++) 
            if (indegree[i] == 0) 
                q.push(i);

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int i : adj[node]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        if (topo.size() != k) return {}; 
        return topo;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> arr(k, vector<int>(k, 0));

        vector<int> rowOrder = f(rowConditions, k);
        if (rowOrder.empty()) return {}; 
        
        vector<int> colOrder = f(colConditions, k);
        if (colOrder.empty()) return {}; 

        vector<int> rowPos(k), colPos(k);
        for (int i = 0; i < k; i++) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        for (int i = 0; i < k; i++) {
            arr[rowPos[i]][colPos[i]] = i + 1; 
        }

        return arr;
    }
};