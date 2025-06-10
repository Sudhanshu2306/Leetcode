class Solution {
public:
    void f(vector<int> &nums, int i, vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(nums); return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            f(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        f(nums,0,ans);
        sort(ans.begin(),ans.end());

        return ans;
    }
};