class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i].size()>n){
                n=nums[i].size();
            }
        }
        int m=nums.size();
        vector<vector<int>> res(m+n);
        for(int i=0;i<m;i++){
            for(int j=0;j<nums[i].size();j++){
                res[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0;i<res.size();i++){
            reverse(res[i].begin(),res[i].end());
        }
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                ans.push_back(res[i][j]);
            }
        }
        
        return ans;
    }
};