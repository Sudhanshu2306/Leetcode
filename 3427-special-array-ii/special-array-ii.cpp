class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        int i=0;
        vector<int> temp(nums.size(), 0);
        
        for (int i = 1; i < nums.size(); i++) {
            temp[i] = temp[i - 1];
            if ((nums[i - 1] % 2) == (nums[i] % 2)) {
                temp[i]++;
            }
        }
        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            // bool flag = true;
            
            if (temp[y] - temp[x] > 0) {
                ans[i] = false;
            } 
            else {
                ans[i] = true;
            }
            // ans[i] = flag;
        }
        return ans;
    }
};