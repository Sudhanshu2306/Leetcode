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
    bool rootToLeafSum(TreeNode* root, int targetSum,int sum){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            sum+=root->val;
            if(sum==targetSum){
                return true;
            }
        }
        return rootToLeafSum(root->left,targetSum, sum+root->val) ||                      rootToLeafSum(root->right,targetSum, sum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int sum=0;
        return rootToLeafSum(root,targetSum,sum);

    }
};