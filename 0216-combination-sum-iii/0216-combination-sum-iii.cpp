class Solution {
public:
    vector<vector<int>> ans;
    vector<int> val;
    int nl, kl;

    void solve(vector<int> &arr, int id, int target) {
        if(target < 0) return;
        if(target == 0) {
            if(arr.size() == kl) ans.push_back(arr);
            return;
        }
        for(int i = id; i < nl; i++) {
            arr.push_back(val[i]);
            solve(arr, i + 1, target - val[i]);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        nl = 9, kl = k;
        for (int i = 1; i <= 9; i++) val.push_back(i);
        vector<int> arr;
        solve(arr, 0, n);
        return ans;
    }
};