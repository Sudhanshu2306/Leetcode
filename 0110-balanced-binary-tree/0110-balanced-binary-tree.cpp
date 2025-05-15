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
    int height(TreeNode* node){
        if(node==nullptr) return 0;

        int left=height(node->left);
        int right=height(node->right);
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;

        int leftH=height(root->left);
        int rightH=height(root->right);

        if(abs(leftH-rightH)>1) return false;

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        return (left && right);
    }
};