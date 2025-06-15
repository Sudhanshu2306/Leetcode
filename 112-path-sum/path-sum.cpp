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
    bool dfs(TreeNode* node, int x, int sum=0){
        if(node==nullptr) return false;
        
        if(node->left==nullptr && node->right==nullptr){
            sum+=node->val;
            if(sum==x) return true;
        }
        sum+=node->val;
        return dfs(node->left,x,sum) || dfs(node->right,x,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return dfs(root,targetSum,sum);
    }
};