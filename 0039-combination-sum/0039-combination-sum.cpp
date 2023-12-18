class Solution {
public:
    void recursion(vector<int> &ans, int index, int target, vector<int>&candidates, vector<vector<int>> &res){
        if(index==candidates.size()){
            if(target==0)
                res.push_back(ans);
            return;
        }
        if(target>=candidates[index]){
            ans.push_back(candidates[index]);
            recursion(ans,index,target-candidates[index],candidates,res);
            ans.pop_back();
        }
        recursion(ans,index+1,target,candidates,res);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        recursion(ans,0,target,candidates,res);
        return res;
    }
};