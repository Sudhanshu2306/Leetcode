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
    int prevSum=0;
    void f(TreeNode* root){
        if(root==nullptr) return;

        // right - center - left
        if(root->right) 
            f(root->right);

        root->val+=prevSum;
        prevSum=root->val;

        if(root->left)
            f(root->left);

    }
    TreeNode* bstToGst(TreeNode* root) {
        f(root);
        return root;
    }
};