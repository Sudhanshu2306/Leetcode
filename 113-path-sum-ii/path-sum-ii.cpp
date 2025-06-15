/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int t, int sum, vector<vector<int>> &ans, vector<int> &x){
        if(root==nullptr) return;
        sum+=root->val;
        x.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==t){
                ans.push_back(x);
            }
        }
        else{
            dfs(root->left,t,sum,ans,x);
            dfs(root->right,t,sum,ans,x);
        }
        x.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> x;
        int sum=0;
        dfs(root,targetSum,sum,ans,x);
        return ans;
    }
};