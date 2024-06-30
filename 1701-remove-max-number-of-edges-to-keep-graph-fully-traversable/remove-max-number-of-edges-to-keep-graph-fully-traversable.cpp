class Solution {
public:
    vector<int> parent, parent1;
    int find(int v) {
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    int Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return 0;
        }
        parent[b] = a;
        return 1;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        parent.resize(n + 1);
        parent1.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        int res = 0, count1 = 0, count2 = 0;
        for (auto& i : edges) {
            if (i[0] == 3) {
                if (Union(i[1], i[2])) {
                    count1++;
                    count2++;
                } else {
                    res++;
                }
            }
        }
        parent1=parent;
        for (auto& i : edges) {
            if (i[0] == 2) {
                if (Union(i[1], i[2])) {
                    count2++;
                } else {
                    res++;
                }
            }
        }
        parent=parent1;
        for (auto& i : edges) {
            if (i[0] == 1) {
                if (Union(i[1], i[2])) {
                    count1++;
                } else {
                    res++;
                }
            }
        }
        return (count1==n-1 and count2==n-1)?res:-1;
    }
};