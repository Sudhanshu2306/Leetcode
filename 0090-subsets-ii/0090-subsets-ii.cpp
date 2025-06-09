class Solution {
public:
    void f(int i, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(ds); return;
        }

        ds.push_back(nums[i]);
        f(i+1,nums,ds,ans);
        ds.pop_back();

        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        f(i+1,nums,ds,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> ds;
        f(0,nums,ds,ans);
        return ans;
    }

};