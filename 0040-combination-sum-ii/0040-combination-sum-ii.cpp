class Solution {
public:
    void recursion(vector<int> &ans, int index, int target, vector<int>&candidates, vector<vector<int>> &res){
        if(target==0){
            res.push_back(ans);
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i-1]==candidates[i]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            ans.push_back(candidates[i]);
            recursion(ans,i+1,target-candidates[i],candidates,res);
            ans.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        recursion(ans,0,target,candidates,res);
        return res;
    }
};